#include "core/team/TeamBuilder.h" // komentarz: budowa składu
#include "core/team/PlayerFactory.h" // komentarz: fabryka
#include "core/team/RandomCompositionPolicy.h" // komentarz: los planu
#include "core/random/DefaultRandomRange.h" // komentarz: RNG
#include "app/stats/PlainTextStatsFormatter.h" // komentarz: formatter TXT
#include "app/stats/ColumnCostFormatter.h" // komentarz: wyrównanie kolumn
#include "app/io/TextFileWriter.h" // komentarz: overwrite
#include "app/io/TextFileAppender.h" // komentarz: append
#include "app/stats/SaveTeamStatsService.h" // komentarz: snapshot → write
#include "app/sim/StdClock.h" // komentarz: zegar
#include "app/sim/RandomActionSelector.h" // komentarz: wybór akcji
#include "app/sim/StaminaDrainSimulator.h" // komentarz: pętla
#include "app/sim/effects/MovementEffect.h" // komentarz: efekt -1 dla graczy bez piłki
#include "app/sim/effects/MovementEffect.h"
#include <iostream> // komentarz: cerr

int main() {
    try {
        DefaultRandomRange rng; // komentarz: RNG
        RandomCompositionPolicy policy(rng); // komentarz: plan
        PlayerFactory factory; // komentarz: gracze ready-to-use
        TeamBuilder builder(factory, policy); // komentarz: GK→DEF→MID→ATT
        Team team = builder.build(); // komentarz: skład

        auto field = std::make_unique<ColumnCostFormatter>(2, " , "); // komentarz: width=2
        PlainTextStatsFormatter formatter(std::move(field)); // komentarz: format
        TextFileWriter writer; // komentarz: overwrite
        SaveTeamStatsService service(formatter, writer); // komentarz: serwis snapshotów
        const std::string path = "FootballPlayerStatistic.txt"; // komentarz: plik
        service.save(team, path); // komentarz: snapshot startowy

        TextFileAppender appender; // komentarz: append
        StdClock clock; // komentarz: zegar
        RandomActionSelector selector(rng); // komentarz: wybór akcji
        StaminaDrainSimulator sim(selector, clock, appender, service); // komentarz: DI
        sim.addPreActionEffect(std::make_unique<MovementEffect>()); // komentarz: -1 wigor dla 9 off-ball (bez GK i bez wykonującego)
        sim.runUntilExhausted(team, path, 3000); // komentarz: co 3 s: adnotacja → stan po
    } catch (const std::exception & ex) {
        std::cerr << "Błąd: " << ex.what() << std::endl; // komentarz: log
        return 1; // komentarz: error code
    }
    return 0; // komentarz: OK
}
