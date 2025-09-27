#pragma once

#include <random>

class IRandomRange {
public:
 virtual ~IRandomRange() = default;
 virtual int roll(int, int) = 0;
};

