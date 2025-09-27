#pragma once

#include "core/random/StaminaCostRandom.h"
#include "core/random/IRandomRange.h"
#include "core/players/IZagranie.h"
#include <optional>

class TemplateZagranie : public IZagranie {
public:
    int buildStaminaCost() override;
    int getStaminaCost() const override;
private:
    StaminaCostRandom staminaCostRandom;
    std::optional<int> cachedCost;
};

