#pragma once

#include <memory>
#include "core/players/Goalkeeper.h"
#include "core/players/Obronca.h"
#include "core/players/Pomocnik.h"
#include "core/players/Napastnik.h"


class IPlayerFactory {
public:
    virtual ~IPlayerFactory() = default; // komentarz: interfejs polimorficzny
    virtual std::unique_ptr<APilkarz> makeGoalkeeper() = 0;
    virtual std::unique_ptr<APilkarz> makeDefender() = 0; // komentarz: obrońca
    virtual std::unique_ptr<APilkarz> makeMid() = 0; // komentarz: pomocnik
    virtual std::unique_ptr<APilkarz> makeStriker() = 0; // komentarz: napastnik
};