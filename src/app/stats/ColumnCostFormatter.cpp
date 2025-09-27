#include "ColumnCostFormatter.h"
#include <sstream>
#include <iomanip>

ColumnCostFormatter::ColumnCostFormatter(int numberWidth, std::string delimiter)
        : width(numberWidth)
        , delim(std::move(delimiter)) {}

std::string ColumnCostFormatter::format(int value, bool isLast) const {
    std::ostringstream ss; // komentarz: bufor na wynik
    ss << std::setw(width) << value; // komentarz: wyrównanie do prawej
    if (!isLast) { ss << delim; } // komentarz: separator tylko gdy nie ostatnie pole
    return ss.str(); // komentarz: zwrot wyniku
}
