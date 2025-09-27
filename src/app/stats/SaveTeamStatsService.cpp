// SaveTeamStatsService.cpp
#include "SaveTeamStatsService.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

SaveTeamStatsService::SaveTeamStatsService(IStatsFormatter & f, IFileWriter & w)
        : formatter(f)
        , writer(w)
{
}

std::vector<std::string> SaveTeamStatsService::buildRoleLabels(const Team & team) const {
    std::vector<std::string> labels; // komentarz: etykiety
    const auto & plan = team.getPlan(); // komentarz: plan
    labels.reserve(team.size()); // komentarz: alokacja
    for (int i = 0 ; i < plan.gk ; ++i) { labels.push_back("GK"); } // komentarz: krótkie skróty jak na screenie
    for (int i = 0 ; i < plan.def ; ++i) { labels.push_back("DEF"); }
    for (int i = 0 ; i < plan.mid ; ++i) { labels.push_back("MID"); }
    for (int i = 0 ; i < plan.att ; ++i) { labels.push_back("ATT"); }
    return labels; // komentarz: etykiety
}

std::vector<std::string> SaveTeamStatsService::buildSnapshot(const Team & team) const {
    const auto rows = collector.collect(team); // komentarz: PlayerStats
    const auto labels = buildRoleLabels(team); // komentarz: role
    if (labels.size() != rows.size()) {
        throw std::logic_error("labels.size() != rows.size()");
    } // komentarz: spójność
    std::vector<std::string> lines; // komentarz: wynik
    lines.reserve(2 + rows.size()); // komentarz: nagłówki + wiersze
    {
        std::ostringstream h;
        h << "Squad: " << team.size(); lines.push_back(h.str());
    } // komentarz: nagłówek
    {
        const auto & p = team.getPlan();
        std::ostringstream h;
        h << "Scheme: (" << p.def << "-" << p.mid << "-" << p.att << ")";
        lines.push_back(h.str());
    } // komentarz: nagłówek
    const auto rowLines = formatter.formatRows(labels, rows); // komentarz: linie graczy
    lines.insert(lines.end(), rowLines.begin(), rowLines.end()); // komentarz: dołącz
    return lines; // komentarz: snapshot gotowy
}

std::vector<std::string> SaveTeamStatsService::buildSnapshotWithNote(const Team & team, std::size_t noteIndex, const std::string & note) const {
    auto lines = buildSnapshot(team); // komentarz: bazowy snapshot
    const std::size_t header = 2; // komentarz: 0=Squad, 1=Scheme
    const std::size_t idx = header + noteIndex; // komentarz: przesunięcie do wiersza gracza
    if (idx < lines.size()) { lines[idx] += "  " + note; } // komentarz: dopnij „Uwaga! …” do właściwego wiersza
    return lines; // komentarz: snapshot z adnotacją
}

void SaveTeamStatsService::save(const Team & team, const std::string & path) {
    const auto lines = buildSnapshot(team); // komentarz: snapshot startowy
    writer.overwrite(path, lines); // komentarz: nadpisz plik
}

void SaveTeamStatsService::overwriteSnapshot(const Team & team, const std::string & path) const {
    const auto lines = buildSnapshot(team); // komentarz: pełny snapshot
    writer.overwrite(path, lines); // komentarz: nadpisz plik
}

void SaveTeamStatsService::overwriteSnapshotWithNote(const Team & team, std::size_t noteIndex, const std::string & note, const std::string & path) const {
    const auto lines = buildSnapshotWithNote(team, noteIndex, note); // komentarz: snapshot z adnotacją
    writer.overwrite(path, lines); // komentarz: nadpisz plik
}

