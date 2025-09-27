#include "TeamStatsCollector.h"

std::vector<PlayerStats> TeamStatsCollector::collect(const Team & team) const { // komentarz: dopasowane do .h
    std::vector<PlayerStats> rows; // komentarz: wynik
    const auto & players = team.getPlayers(); // komentarz: gracze
    rows.reserve(players.size()); // komentarz: alokacja
    for (const auto & up : players) {
        const auto v = up->getStaminaCostStats(); // komentarz: [pass,shot,slide]
        const int passCost = v.size() > 0 ? v[0] : 0; // komentarz: safe
        const int shotCost = v.size() > 1 ? v[1] : 0; // komentarz: safe
        const int slideCost = v.size() > 2 ? v[2] : 0; // komentarz: safe
        const int vigor = up->getWitalnosc(); // komentarz: bieżący wigor
        rows.push_back(PlayerStats{passCost, shotCost, slideCost, vigor}); // komentarz: jeden wiersz na gracza
    }
    return rows; // komentarz: zwrot
}
