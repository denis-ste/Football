#pragma once

#include "core/players/APilkarz.h"
#include "PositionsPlan.h"
#include "vector"
#include "memory"


class Team {
public:
    void add(std::unique_ptr<APilkarz>);
    std::size_t size() const;
    const std::vector<std::unique_ptr<APilkarz>>& getPlayers() const;
    void setPlan(const PositionsPlan&);
    const PositionsPlan& getPlan() const;
private:
    std::vector<std::unique_ptr<APilkarz>> players;
    PositionsPlan plan{1,4,4,2};
};

