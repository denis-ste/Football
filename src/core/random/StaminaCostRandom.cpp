#include "StaminaCostRandom.h"

int StaminaCostRandom::rollInRange10() {
    return DefaultRandomRange::roll(defaultMin, defaultMax);
}
