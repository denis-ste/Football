#pragma once
#include <string>

// komentarz: Strategy – formatuje pojedynczy koszt (szerokość, przecinek, spacje)
class ICostFieldFormatter {
public:
    virtual ~ICostFieldFormatter() = default;
    virtual std::string format(int value, bool isLast) const = 0; // komentarz: isLast = czy ostatnie pole w wierszu
};
