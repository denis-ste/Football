// IActionSelector.h
#pragma once
#include <cstddef>

struct ChosenAction {
    std::size_t playerIndex; // komentarz: który zawodnik
    int skillIndex; // komentarz: 0=Podanie, 1=Strzał, 2=Wślizg
};

class IActionSelector {
public:
    virtual ~IActionSelector() = default; // komentarz: interfejs
    virtual ChosenAction pick(const class Team & team) = 0; // komentarz: wybierz spośród żywych
};
