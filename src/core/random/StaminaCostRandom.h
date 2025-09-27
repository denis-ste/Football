#pragma once

#include "DefaultRandomRange.h"

class StaminaCostRandom : private DefaultRandomRange {
public:
    int rollInRange10() ;
private:
    int defaultMin = 1;
    int defaultMax = 10;
};

