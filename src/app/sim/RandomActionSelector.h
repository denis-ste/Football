#pragma once
#include "IActionSelector.h"
#include "core/random/IRandomRange.h"

class RandomActionSelector : public IActionSelector {
public:
    explicit RandomActionSelector(IRandomRange & rng); // komentarz: wstrzykuj RNG
    ChosenAction pick(const Team & team) override; // komentarz: wybierz gracza z wigorem > 0 i akcję 0..2
private:
    IRandomRange & rng; // komentarz: generator
};
