#include "../Test.h"
#include "CoreMinimal.h"
#include <PlayerStats/PlayerStatsComponent.h>

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlayerStatsComponentTest,
                                 "Stats.PlayerStatsComponentTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FPlayerStatsComponentTest::RunTest(const FString &Parameters) {
  TestHelper helper;
  // Stats Component Set Up
  FStatsStruct testcase = {100f, 201f, 100f, 100f, 100f, 0f,
                           0f,   0f,   0f,   0f,   0f,   0f};
  PlayerStatsComponent stats;
  stats.ComponentSetUp(testcase);
  // stats.ComponentSetUp();

  // Test
  // Raise Upper limit
  // stats type , value, time
  stats.RaiseLimit(StatsType::HP, 100f, 2f);
  helper.Equal(stats.GetStats(StatsType::HP), 301f, "HP is not 301");
  // wait 2s
  helper.Equal(stats.GetStats(StatsType::HP), 201f, "HP is not 201");

  stats.LowerLimit(StatsType::AD, 200f, 2f);
  helper.Equal(stats.GetStats(StatsType::AD), 0, "AD is not 0");
  // wait 2s
  helper.Equal(stats.GetStats(StatsType::AD), 100f, "AD is not 100");

  // Buff and debuff
  stats.Buff(StatsType::HP, 1.1f, 2f);
  helper.Equal(stats.GetStats(StatsType::HP), 221f, "HP is not 221");
  // wait 2s
  helper.Equal(stats.GetStats(StatsType::HP), 201f, "HP is not 201");

  stats.Debuff(StatsType::HP, 0.75f, 2f);
  helper.Equal(stats.GetStats(StatsType::HP), 150.75f, "HP is not 150.75");
  stats.RaiseLimit(StatsType::HP, 100f, 2f);
  helper.Equal(stats.GetStats(StatsType::HP), 225.75f, "HP is not 225.75");
  // wait 2s
  helper.Equal(stats.GetStats(StatsType::HP), 201f, "HP is not 201");

  // Heal and Damage
  // NOTE:固定ダメージ
  stats.DamageHP(10);
  stats.DamageMP(10);
  helper.Equal(stats.GetStats(StatsType::HP), 191ff, "HP is not 191");
  helper.Equal(stats.GetStats(StatsType::MP), 90f, "MP is not 90");
  stats.HealHP(5);
  stats.HealMP(20);
  helper.Equal(stats.GetStats(StatsType::HP), 196f, "HP is not 196");
  helper.Equal(stats.GetStats(StatsType::MP), 100f, "MP is not 100");

  return helper.IsTest();
}
