// StdClock.h
#pragma once
#include "IClock.h"

class StdClock : public IClock {
public:
    void sleepMs(int ms) override; // komentarz: implementacja z std::this_thread
};
