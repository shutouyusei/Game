#include "../Test.h"
#include "CoreMinimal.h"
#include <PlayerStatsComponent.h>

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlayerStatsComponentTest,
                                 "Stats.PlayerStatsComponentTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FPlayerStatsComponentTest::RunTest(const FString &Parameters) {
  TestHelper helper;
  // Stats Component Set Up
  FStatsStruct testcase = {100f, 201f, 100f, 100f, 100f, 0f,
                           0f,   0f,   0f,   0f,   0f,   0f};
  PlayerStatsComponent statsComponent;
  statsComponent.ComponentSetUp(testcase);
  StatsBase *stats = statsComponent.GetStats();
  // stats.ComponentSetUp();

  // Test
  // Raise Upper limit
  // stats type , value, time
  stats.RaiseLimit(StatsType::HP, 100f);
  helper.Equal(stats.GetStats(StatsType::HP), 301f, "HP is not 301");

  stats.LowerLimit(StatsType::AD, 200f);
  helper.Equal(stats.GetStats(StatsType::AD), 0, "AD is not 0");

  // Heal and Damage
  // NOTE:固定ダメージ
  stats.DamageHP(10);
  stats.DamageMP(10);
  helper.Equal(stats.GetStats(StatsType::HP), 211ff, "HP is not 191");
  helper.Equal(stats.GetStats(StatsType::MP), 140f, "MP is not 90");
  stats.HealHP(5);
  stats.HealMP(30);
  helper.Equal(stats.GetStats(StatsType::HP), 216f, "HP is not 216");
  helper.Equal(stats.GetStats(StatsType::MP), 150f, "MP is not 150");

  statsComponent.ComponentCleanUp();
  return helper.IsTest();
}
