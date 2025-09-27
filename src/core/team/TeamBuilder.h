#pragma once

#include "Team.h"
#include "IPlayerFactory.h"
#include "ICompositionPolicy.h"

class TeamBuilder {
public:
    TeamBuilder(IPlayerFactory& f, ICompositionPolicy& p) : factory(f), policy(p) {}

    Team build();
    private:
    IPlayerFactory& factory;
    ICompositionPolicy& policy;
};
