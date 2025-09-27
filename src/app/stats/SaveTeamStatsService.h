// SaveTeamStatsService.h
#pragma once
#include <string>
#include <vector>
#include "core/team/Team.h"
#include "IStatsFormatter.h"
#include "app/io/IFileWriter.h"
#include "TeamStatsCollector.h"

class SaveTeamStatsService {
public:
    SaveTeamStatsService(IStatsFormatter & f, IFileWriter & w); // komentarz: DI: formatter + writer
    void save(const Team & team, const std::string & path); // komentarz: nadpisz plik snapshotem startowym

    // === NOWE: budowa linii snapshotu bez zapisu do pliku ===
    std::vector<std::string> buildSnapshot(const Team & team) const; // komentarz: pełny snapshot bez adnotacji
    std::vector<std::string> buildSnapshotWithNote(const Team & team, std::size_t noteIndex, const std::string & note) const; // komentarz: pełny snapshot z adnotacją

    // === Udostępniamy etykiety (przydadzą się gdzie indziej) ===
    std::vector<std::string> buildRoleLabels(const Team & team) const; // komentarz: GK/DEF/MID/ATT

    // === NOWE: twarde nadpisanie pliku gotowym snapshotem ===
    void overwriteSnapshot(const Team & team, const std::string & path) const;
    void overwriteSnapshotWithNote(const Team & team, std::size_t noteIndex, const std::string & note, const std::string & path) const;


private:
    IStatsFormatter & formatter; // komentarz: strategia formatowania
    IFileWriter & writer; // komentarz: strategia zapisu
    TeamStatsCollector collector; // komentarz: zbiera PlayerStats
};
