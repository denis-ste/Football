// RandomActionSelector.cpp
#include "RandomActionSelector.h"
#include "core/team/Team.h"

RandomActionSelector::RandomActionSelector(IRandomRange & r) : rng(r) {}

ChosenAction RandomActionSelector::pick(const Team & team) {
    const auto & players = team.getPlayers(); // komentarz: snapshot
    if (players.empty())
    {
        throw std::logic_error("team has no players");
    } // komentarz: guard
    int tries = 1000; // komentarz: bezpiecznik
    while (tries-- > 0)
    {
        const int idx = rng.roll(0, static_cast<int>(players.size()) - 1); // komentarz: los indeksu
        if (idx >= 0 && static_cast<std::size_t>(idx) < players.size() && players[idx]->getWitalnosc() > 0) { // komentarz: żywy w zakresie
            const int skill = rng.roll(0, 2); // komentarz: 0..2
            return ChosenAction{static_cast<std::size_t>(idx), skill}; // komentarz: zwróć
        }
    }
    for (std::size_t i = 0 ; i < players.size() ; ++i) {
        if (players[i]->getWitalnosc() > 0) {
            return ChosenAction{i, 0};
        }
    } // komentarz: deterministyczny fallback na pierwszego żywego
    throw std::logic_error("no alive players to pick"); // komentarz: wszyscy padli
}

