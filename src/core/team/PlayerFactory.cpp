#include "PlayerFactory.h"


std::unique_ptr<APilkarz> PlayerFactory::makeDefender() {
    auto player = std::make_unique<Obronca>(); // komentarz: stwórz obrońcę
    player->buildSkills(); // komentarz: zbuduj 3 skille
    player->buildStaminaCosts(); // komentarz: ustal koszty (cache)
    return player; // komentarz: gotowy obiekt
}


std::unique_ptr<APilkarz> PlayerFactory::makeMid() {
    auto player = std::make_unique<Pomocnik>();
    player->buildSkills();
    player->buildStaminaCosts(); // komentarz: ustal koszty (cache)
    return player;
}

std::unique_ptr<APilkarz> PlayerFactory::makeStriker() {
    auto player = std::make_unique<Napastnik>();
    player->buildSkills();
    player->buildStaminaCosts(); // komentarz: ustal koszty (cache)
    return player;
}

std::unique_ptr<APilkarz> PlayerFactory::makeGoalkeeper() {
    auto player = std::make_unique<Goalkeeper>();
    player->buildSkills();
    player->buildStaminaCosts(); // komentarz: ustal koszty (cache)
    return player;
}
