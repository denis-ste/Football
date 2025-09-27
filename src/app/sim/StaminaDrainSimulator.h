// StaminaDrainSimulator.h
#pragma once
#include <string>
#include <unordered_map>
#include "core/team/Team.h"
#include "app/io/IFileAppender.h"
#include "IActionSelector.h"
#include "IClock.h"
#include "app/stats/SaveTeamStatsService.h"

class StaminaDrainSimulator {
public:
    StaminaDrainSimulator(IActionSelector & selector, IClock & clock, IFileAppender & appender, SaveTeamStatsService & statsService); // komentarz: DI + serwis snapshotów
    void runUntilExhausted(Team & team, const std::string & path, int delayMs); // komentarz: pętla co 3 s (naprzemiennie: adnotacja → stan po)
private:
    IActionSelector & selector; // komentarz: wybór akcji
    IClock & clock; // komentarz: zegar
    IFileAppender & appender; // komentarz: dopisywanie
    SaveTeamStatsService & stats; // komentarz: budowa snapshotów
    std::unordered_map<std::size_t, int> actionsCount; // komentarz: licznik akcji
    static const char * skillName(int idx); // komentarz: 0/1/2 → nazwa

};
