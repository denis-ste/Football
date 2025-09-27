
#include "TemplateZagranie.h"
#include "core/players/APilkarz.h"
#include "iostream"


int TemplateZagranie::buildStaminaCost() {
    if(!cachedCost.has_value()) {
        const int v = staminaCostRandom.rollInRange10();
        cachedCost = v;
    }
    return *cachedCost;
}

int TemplateZagranie::getStaminaCost() const {
    if (!cachedCost.has_value()) {
        throw std::logic_error("Stamina cost not built"); // komentarz: czysty odczyt → wyjątek, nie cout
    }
    return *cachedCost; // komentarz: stabilna wartość
}