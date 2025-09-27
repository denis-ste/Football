// StdClock.cpp
#include "StdClock.h"
#include <thread>
#include <chrono>

void StdClock::sleepMs(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms)); // komentarz: realny sleep
}
