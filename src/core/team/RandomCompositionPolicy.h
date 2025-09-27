#pragma once
// komentarz: losowy plan z ograniczeniami: DEF 3..5, MID 3..5, ATT ≥1, GK=1

#include <algorithm>
#include "core/team/ICompositionPolicy.h"
#include "core/random/IRandomRange.h"

class RandomCompositionPolicy final : public ICompositionPolicy
{
public:
    explicit RandomCompositionPolicy(IRandomRange & r)
            : rng(r)
    {
    }
    PositionsPlan choose() override;
private:
    IRandomRange & rng;
};
