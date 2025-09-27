#pragma once
#include "IStatsFormatter.h"
#include "ICostFieldFormatter.h"
#include <memory>

// komentarz: formatter TXT korzystający z mini-strategii pól
class PlainTextStatsFormatter : public IStatsFormatter {
public:
    explicit PlainTextStatsFormatter(std::unique_ptr<ICostFieldFormatter> f); // komentarz: DI
    std::vector<std::string> formatRows(const std::vector<std::string> & labels, const std::vector<PlayerStats> & rows) const override; // komentarz: const override
private:
    std::unique_ptr<ICostFieldFormatter> field; // komentarz: strategia formatowania pól
};
