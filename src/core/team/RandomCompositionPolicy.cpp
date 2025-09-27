#include "RandomCompositionPolicy.h"

PositionsPlan RandomCompositionPolicy::choose() {
        const int gk = 1;
        const int fieldPlayers = 10;
        const int defendersCount = rng.roll(3, 5);
        const int remainingAfterDef = fieldPlayers - defendersCount;
        const int midfieldersMin = std::max(3, remainingAfterDef - 5);
        const int midfieldersMax = std::min(5, remainingAfterDef - 1);
        const int midfieldersCount = rng.roll(midfieldersMin, midfieldersMax);
        const int attackersCount = fieldPlayers - defendersCount - midfieldersCount;
        PositionsPlan plan{gk, defendersCount, midfieldersCount, attackersCount};
        return plan;
}