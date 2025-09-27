#include "TeamBuilder.h"

Team TeamBuilder::build() {
    const PositionsPlan plan = policy.choose();
    Team t;
    t.setPlan(plan);
    for(int i = 0; i < plan.gk; ++i) {
        t.add(factory.makeGoalkeeper());
    }
    for (int i = 0; i < plan.def; ++i) {
        t.add(factory.makeDefender());
    }
    for (int i = 0; i < plan.mid; ++i) {
        t.add(factory.makeMid());
    }
    for (int i = 0; i < plan.att; ++i) {
        t.add(factory.makeStriker());
    }
    return t;
}