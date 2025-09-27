#include "PlainTextStatsFormatter.h"
#include <sstream>
#include <algorithm>

PlainTextStatsFormatter::PlainTextStatsFormatter(std::unique_ptr<ICostFieldFormatter> f)
        : field(std::move(f))
{
}

std::vector<std::string> PlainTextStatsFormatter::formatRows(const std::vector<std::string> & labels, const std::vector<PlayerStats> & rows) const { // komentarz: const
    std::vector<std::string> out; // komentarz: wynik
    const std::size_t n = std::min(labels.size(), rows.size()); // komentarz: pas bezpieczeństwa
    out.reserve(n); // komentarz: alokacja
    for (std::size_t i = 0 ; i < n ; ++i) {
        std::ostringstream line; // komentarz: bufor
        line << labels[i] << " : "; // komentarz: rola
        line << field->format(rows[i].passCost, false); // komentarz: koszt 1
        line << field->format(rows[i].shotCost, false); // komentarz: koszt 2
        line << field->format(rows[i].slideCost, true); // komentarz: koszt 3
        line << "   Wigor : " << rows[i].vigor; // komentarz: wigor
        out.push_back(line.str()); // komentarz: dodaj
    }
    return out; // komentarz: zwróć
}
