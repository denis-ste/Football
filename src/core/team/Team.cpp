
#include "core/team/Team.h"

void Team::add(std::unique_ptr<APilkarz> p) {
    players.push_back(std::move(p));
}


std::size_t Team::size() const {
    return players.size();
}

const std::vector<std::unique_ptr<APilkarz>> &Team::getPlayers() const {
    return players;
}

void Team::setPlan(const PositionsPlan &p) {
    plan = p;
}

const PositionsPlan &Team::getPlan() const {
    return plan;
}