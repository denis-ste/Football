#pragma once
#include <cstddef>
#include <vector>
#include <optional>
#include "core/team/Team.h"

// komentarz: Strategy – efekt tury uruchamiany PRZED rozliczeniem akcji
class ITurnEffect {
public:
    virtual ~ITurnEffect() = default; // komentarz: wirtualny destruktor
    virtual void offBallRunningVigorDecreaseEffect(Team & team, const std::vector<std::string> & roleLabels, std::optional<std::size_t> actingIndex) = 0; // komentarz: efekt fazy pre-action
};
