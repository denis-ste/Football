#pragma once
#include "ICostFieldFormatter.h"
#include <string>

// komentarz: stała szerokość liczby + kontrola separatora (Strategy)
class ColumnCostFormatter : public ICostFieldFormatter {
public:
    ColumnCostFormatter() = default; // komentarz: użyje domyślnych z pól
    ColumnCostFormatter(int, std::string); // komentarz: nadpisanie domyślnych
    std::string format(int value, bool isLast) const override; // komentarz: format pojedynczego pola
private:
    int width {2}; // komentarz: domyślna szerokość liczby (np. " 7" / "10")
    std::string delim {" , "}; // komentarz: domyślny separator między polami
};
