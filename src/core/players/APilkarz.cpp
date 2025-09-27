#include "APilkarz.h"

int APilkarz::getWitalnosc() {
    return witalnosc; // komentarz: odczyt
}

int APilkarz::setWitalnosc(int v) {
    witalnosc = v; // komentarz: zapis
    return witalnosc; // komentarz: zwrot
}

void APilkarz::addSkill(std::unique_ptr<IZagranie> z) {
    skills.push_back(std::move(z)); // komentarz: dodaj skill
}

void APilkarz::buildSkills() {
    addSkill(std::make_unique<Podanie>()); // komentarz: skill 1
    addSkill(std::make_unique<Strzal>()); // komentarz: skill 2
    addSkill(std::make_unique<Wslizg>()); // komentarz: skill 3
}

void APilkarz::buildStaminaCosts() {
    for (auto & s : skills) {
        s->buildStaminaCost(); // komentarz: ustal koszt i zcache’uj
    }
}

std::vector<int> APilkarz::getStaminaCostStats() const {
    std::vector<int> out; // komentarz: wynik
    out.reserve(skills.size()); // komentarz: alokacja (to NIE jest odwracanie!)
    for (const auto & s : skills) {
        out.push_back(s->getStaminaCost()); // komentarz: czysty odczyt
    }
    return out; // komentarz: zwróć 3 liczby
}



