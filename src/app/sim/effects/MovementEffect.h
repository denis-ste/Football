#pragma once
#include "app/sim/ITurnEffect.h"

// komentarz: obniża wigor graczy bez piłki, pomija GK i aktualnego wykonawcę
class MovementEffect : public ITurnEffect {
public:
    void offBallRunningVigorDecreaseEffect(Team &team, const std::vector<std::string> &roleLabels, std::optional<std::size_t> actingIndex) override;
private:
    int deltaVigorOffBall { -1 }; // komentarz: ujemna delta za bieganie bez piłki
};
