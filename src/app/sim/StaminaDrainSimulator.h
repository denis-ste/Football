// StaminaDrainSimulator.h
#pragma once
#include <string>
#include <unordered_map>
#include "core/team/Team.h"
#include "app/io/IFileAppender.h"
#include "IActionSelector.h"
#include "IClock.h"
#include "app/stats/SaveTeamStatsService.h"
#include "ITurnEffect.h"

class StaminaDrainSimulator {
public:
    StaminaDrainSimulator(IActionSelector & selector, IClock & clock, IFileAppender & appender, SaveTeamStatsService & statsService); // komentarz: DI + serwis snapshotów
    void runUntilExhausted(Team & team, const std::string & path, int delayMs); // komentarz: pętla co 3 s (naprzemiennie: adnotacja → stan po)
    void addPreActionEffect(std::unique_ptr<ITurnEffect> e); // komentarz: rejestracja efektu pre-action
private:
    IActionSelector & selector; // komentarz: wybór akcji
    IClock & clock; // komentarz: zegar
    IFileAppender & appender; // komentarz: dopisywanie
    SaveTeamStatsService & stats; // komentarz: budowa snapshotów
    std::unordered_map<std::size_t, int> actionsCount; // komentarz: licznik akcji
    std::vector<std::unique_ptr<ITurnEffect>> preActionEffects; // komentarz: strategie pre-action
    void runPreActionPhase(Team & team, const std::vector<std::string> & labels, std::size_t actingIndex); // komentarz: krok szablonu – faza pre-action
    static const char * skillName(int idx); // komentarz: 0/1/2 → nazwa

};
