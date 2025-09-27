#include "MovementEffect.h"
#include <algorithm>

void MovementEffect::offBallRunningVigorDecreaseEffect(Team &team,
                                                          const std::vector<std::string> &roleLabels,
                                                          std::optional<std::size_t> actingIndex) {
    auto &players = team.getPlayers(); // komentarz: gracze
    for (std::size_t i = 0; i < players.size(); ++i) {
        if (actingIndex.has_value() && i == *actingIndex) {
            continue;
        }// komentarz: posiadacz piłki – bez drenażu
        if (roleLabels[i] == "GK") {
            continue;
        } // komentarz: GK – bez drenażu
        const int before = players[i]->getWitalnosc(); // komentarz: wigor przed
        if (before <= 0) {
            continue;
        } // komentarz: wyczerpanych nie ruszamy
        const int after = std::max(0, before + deltaVigorOffBall); // komentarz: dodaj deltę (−1), clamp do 0
        players[i]->setWitalnosc(after); // komentarz: zapisz
    }
}
