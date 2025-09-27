#pragma once

#include "PositionsPlan.h"

class ICompositionPolicy {
public:
 virtual ~ICompositionPolicy() = default;
 virtual PositionsPlan choose() = 0;
};


