#include <gtest/gtest.h>
#include "core/team/TeamBuilder.h"                  // jest w domain/
#include "core/team/PlayerFactory.h"                // jest w domain/
#include "core/team/RandomCompositionPolicy.h" // jest w domain/random/
#include "core/random/DefaultRandomRange.h"    // jest w domain/random/

TEST(TeamBuilderTest, TeamSizeMatchesPlan) {
    DefaultRandomRange rng;  // komentarz: RNG do polityki
    RandomCompositionPolicy policy(rng);  // komentarz: losowy plan
    PlayerFactory factory;  // komentarz: w pełni inicjalizuje piłkarzy
    TeamBuilder builder(factory, policy);  // komentarz: GK → DEF → MID → ATT
    Team team = builder.build();  // komentarz: budowa zespołu
    const auto & plan = team.getPlan();  // komentarz: użyty plan z zapisany w Team
    const std::size_t expected = static_cast<std::size_t>(plan.gk + plan.def + plan.mid + plan.att);  // komentarz: suma z GK
    EXPECT_EQ(team.size(), expected);  // komentarz: 11 == 1+DEF+MID+ATT
}

