#pragma once

#include <random>
#include <algorithm>

#include "IRandomRange.h"

class DefaultRandomRange : public IRandomRange{
public:
    DefaultRandomRange();
    int roll(int, int) override;
private:
    std::mt19937 engine;
};

