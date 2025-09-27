#include <gtest/gtest.h>
#include "core/team/RandomCompositionPolicy.h" // u Ciebie w random/
#include "core/random/DefaultRandomRange.h"
#include "core/team/PositionsPlan.h"                 // jest w domain/

TEST(RandomCompositionPolicyTest, SatisfiesConstraints)
{
DefaultRandomRange rng;
RandomCompositionPolicy policy(rng);         // bez &rng
const PositionsPlan plan = policy.choose();
ASSERT_EQ(plan.gk, 1);
ASSERT_GE(plan.def, 3);
ASSERT_LE(plan.def, 5);
ASSERT_GE(plan.mid, 3);
ASSERT_LE(plan.mid, 5);
ASSERT_GE(plan.att, 1);
ASSERT_EQ(plan.def + plan.mid + plan.att + plan.gk, 11);
}
