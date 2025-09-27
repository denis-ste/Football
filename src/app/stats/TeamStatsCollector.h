// TeamStatsCollector.h
#pragma once
#include <vector>
#include "core/team/Team.h"
#include "IStatsFormatter.h"

class TeamStatsCollector {
public:
    std::vector<PlayerStats> collect(const Team & team) const; // komentarz: zwraca koszty dla wszystkich
};
