#pragma once
#include <vector>
#include <memory>
#include "core/players/IZagranie.h"
#include "core/players/Podanie.h"
#include "core/players/Strzal.h"
#include "core/players/Wslizg.h"

// komentarz: baza dla piłkarzy
class APilkarz {
public:
    APilkarz() = default;
    virtual ~APilkarz() = default;

    int getWitalnosc();
    int setWitalnosc(int v);
    void buildSkills(); // komentarz: tworzy 3 skille
    void buildStaminaCosts(); // komentarz: buduje koszty skilli (cache)
    std::vector<int> getStaminaCostStats() const; // komentarz: [pass, shot, slide] tylko odczyt
protected:
    void addSkill(std::unique_ptr<IZagranie>);
    std::vector<std::unique_ptr<IZagranie>> skills;
private:
    int witalnosc = 100;

};
