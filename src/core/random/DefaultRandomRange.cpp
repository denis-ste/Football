#include "DefaultRandomRange.h"

DefaultRandomRange::DefaultRandomRange() : engine(std::random_device{}()) {}

int DefaultRandomRange::roll(int min, int max)
{
    if (min > max)
    {
        std::swap(min, max);
    }
    std::uniform_int_distribution<int> dist(min, max);
    return dist(engine);
}
