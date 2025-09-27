// StaminaDrainSimulator.cpp
#include "StaminaDrainSimulator.h"
#include <sstream>
#include <algorithm>

StaminaDrainSimulator::StaminaDrainSimulator(IActionSelector & s, IClock & c, IFileAppender & a, SaveTeamStatsService & svc)
        : selector(s)
        , clock(c)
        , appender(a)
        , stats(svc)
{
}

const char * StaminaDrainSimulator::skillName(int idx) {
    if (idx == 0) { return "Podanie"; } // komentarz: nazwa 0
    if (idx == 1) { return "Strzał"; } // komentarz: nazwa 1
    return "Wślizg"; // komentarz: nazwa 2
}

void StaminaDrainSimulator::runUntilExhausted(Team & team, const std::string & path, int delayMs) {
    const auto & players = team.getPlayers(); // komentarz: snapshot graczy
    if (players.empty()) {
        throw std::logic_error("team has no players");
    } // komentarz: guard
    while (true) {
        const auto choice = selector.pick(team); // komentarz: wybór żywego gracza i akcji
        if (choice.playerIndex >= players.size()) {
            throw std::logic_error("selector picked invalid player index");
        } // komentarz: guard

        clock.sleepMs(delayMs); // komentarz: 3 s przed zapowiedzią
        const auto preCosts = players[choice.playerIndex]->getStaminaCostStats(); // komentarz: koszty [3]
        const int passCost = preCosts.size() > 0 ? preCosts[0] : 0; // komentarz: safe
        const int shotCost = preCosts.size() > 1 ? preCosts[1] : 0; // komentarz: safe
        const int slideCost = preCosts.size() > 2 ? preCosts[2] : 0; // komentarz: safe
        const int idx = choice.skillIndex; // komentarz: 0/1/2
        const int cost = (idx == 0 ? passCost : (idx == 1 ? shotCost : slideCost)); // komentarz: koszt
        const std::string note = std::string("Uwaga! ") + skillName(idx) + " - " + std::to_string(cost); // komentarz: adnotacja
        stats.overwriteSnapshotWithNote(team, choice.playerIndex, note, path); // komentarz: NADPISZ snapshot z uwagą (13 linii)

        clock.sleepMs(delayMs); // komentarz: 3 s do efektu
        auto & player = *players[choice.playerIndex]; // komentarz: gracz
        const int before = player.getWitalnosc(); // komentarz: wigor przed
        const int after = std::max(0, before - cost); // komentarz: clamp 0
        player.setWitalnosc(after); // komentarz: zapisz nowy wigor
        actionsCount[choice.playerIndex] += 1; // komentarz: zlicz akcję
        stats.overwriteSnapshot(team, path); // komentarz: NADPISZ snapshot po akcji (bez uwagi, 13 linii)

        if (after == 0) { // komentarz: koniec – zawodnik wyczerpany
            const auto labels = stats.buildRoleLabels(team); // komentarz: etykiety ról
            std::ostringstream fin; // komentarz: bufor
            fin << "Uwaga! " << labels[choice.playerIndex] << " wyczerpany po liczbie akcji : " << actionsCount[choice.playerIndex]; // komentarz: treść
            const std::string summary = fin.str(); // komentarz: tekst adnotacji
            stats.overwriteSnapshotWithNote(team, choice.playerIndex, summary, path); // komentarz: ostatni snapshot z adnotacją (13 linii)
            break; // komentarz: wyjście z pętli
        }
    }
}


