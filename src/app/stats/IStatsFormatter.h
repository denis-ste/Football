#pragma once
#include <string>
#include <vector>

// komentarz: struktura wiersza statystyk
struct PlayerStats {
    int passCost; // komentarz: koszt podania
    int shotCost; // komentarz: koszt strzału
    int slideCost; // komentarz: koszt wślizgu
    int vigor; // komentarz: bieżący wigor
};

// komentarz: interfejs formatowania – czysty odczyt, więc const
class IStatsFormatter {
public:
    virtual ~IStatsFormatter() = default; // komentarz: wirtualny destruktor
    virtual std::vector<std::string> formatRows(const std::vector<std::string> & labels, const std::vector<PlayerStats> & rows) const = 0; // komentarz: teraz const
};
