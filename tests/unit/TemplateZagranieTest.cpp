
#include <gtest/gtest.h>
#include "core/players/Obronca.h"


// BDD
// Scenario: Witalnosc po ruchu spada
// Given: Obrońca ze zbudowanymi umiejętnościami
// When: Wywołam usePass()
// Then: Witalność jest mniejsza niż przed ruchem i większa lub równa start-10
/*TEST(TemplateZagranieTest, VitalityDecreasesAfterUseSkill)
{
    Obronca o;
    o.buildSkills();
    const int start = o.getWitalnosc();
    o.usePass();
    const int after = o.getWitalnosc();
    ASSERT_LT(after, start);
    ASSERT_GE(after, start - 10);
}

// BDD
// Scenario: Koszt jednego użycia jest w zakresie 1..10
// Given: Obrońca ze zbudowanymi umiejętnościami
// When: Użyję strzału raz
// Then: Spadek witalności mieści się w [1..10]
TEST(TemplateZagranieTest, SingleUseCostIsWithin10Range)
{
    Obronca o;
    o.buildSkills();
    const int start = o.getWitalnosc();
    o.useShot();
    const int delta = start - o.getWitalnosc();
    ASSERT_GE(delta, 1);
    ASSERT_LE(delta, 10);
}*/

// BDD Scenario: Koszt zagrania jest stały dla danego obiektu (raz wylosowany)
// Given: Obrońca ze zbudowanymi umiejętnościami
// When: Dwa razy użyję wślizgu
// Then: Oba spadki witalności są równe i w zakresie 1..10
/*
TEST(TemplateZagranieTest, CostIsFixedPerObject)
{
    Obronca o;
    o.buildSkills();
    const int s0 = o.getWitalnosc();
    o.useSlide();
    const int s1 = o.getWitalnosc();
    o.useSlide();
    const int s2 = o.getWitalnosc();
    const int d1 = s0 - s1;
    const int d2 = s1 - s2;
    ASSERT_EQ(d1, d2);
    ASSERT_GE(d1, 1);
    ASSERT_LE(d1, 10);
}*/
