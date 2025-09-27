#pragma once

#include "IPlayerFactory.h"

class PlayerFactory : public IPlayerFactory  {
    std::unique_ptr<APilkarz> makeGoalkeeper() override;
    std::unique_ptr<APilkarz> makeDefender() override;
    std::unique_ptr<APilkarz> makeMid() override;
    std::unique_ptr<APilkarz> makeStriker() override;
};
