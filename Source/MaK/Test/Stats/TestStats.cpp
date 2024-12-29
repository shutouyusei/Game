#include "../Test.h"
#include "CoreMinimal.h"
#include <StatsComponent.h>
#include <corecrt_wstring.h>
bool operator==(FStatsStruct &a, FStatsStruct &b) {
  bool retval1 = (a.HP == b.HP) && (a.MP == b.MP) && (a.AD == b.AD) &&
                 (a.AP == b.AP) && (a.AR == b.MR) && (a.MR == b.MR);
  bool retval2 = (a.FireRes == b.FireRes) && (a.IceRes == b.IceRes) &&
                 (a.DarkRes == b.DarkRes) && (a.ElecRes == b.ElecRes) &&
                 (a.HolyRes == b.HolyRes);
  return retval1 && retval2;
}
// XXX:大体のエラーこのファイル内だから頑張ってね

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlayerStatsComponentTest,
                                 "Stats.PlayerStatsComponentTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FPlayerStatsComponentTest::RunTest(const FString &Parameters) {
  TestHelper helper;
  // Stats Component Set Up
  FStatsStruct testcase = {100f, 100f, 100f, 100f, 100f, 0f, 0f, 0f, 0f, 0f};
  PlayerStatsComponent statsComponent;
  statsComponent.ComponentSetUp(testcase);
  helper.Equal(statsComponent.GetStats(), testcase, "testcase1");

  StatsBase *stats = statsComponent.Get();
  stats->MP_.Increase(10);
  helper.Equal(110, stats->MP_.Get(), "testcase2");

  stats->MP_.Decrease(10);
  helper.Equal(100, stats->MP_.Get(), "testcase3");

  stats->MP_.SetRatio(1.1);
  helper.Equal(120, stats->MP_.Get(), "testcase4");
  // HP test
  helper.Equal(100, stats->HP_.GetCurrent(), "testcase5");

  stats->HP_.Damage(10);
  helper.Equal(100, stats->HP_.Get(), "testcase6");
  helper.Equal(90, stats->HP_.GetCurrent(), "testcase7");

  stats->HP_.Heal(100);
  helper.Equal(100, stats->HP_.Get(), "testcase8");
  helper.Equal(100, stats->HP_.GetCurrent(), "testcase9");

  statsComponent.ComponentCleanUp();
  return helper.IsTest();
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FStatsComponentTest, "Stats.DeathNotifyTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FStatsComponentTest::RunTest(const FString &Parameters) {
  TestHelper helper;
  // Stats Component Set Up
  FStatsStruct testcase = {100f, 100f, 100f, 100f, 100f, 0f, 0f, 0f, 0f, 0f};
  PlayerStatsComponent statsComponent;
  statsComponent.ComponentSetUp(testcase);
  helper.Equal(statsComponent.GetStats(), testcase, "testcase1");
  StatsBase *stats = statsComponent.Get();

  stats->HP_.Damage(150);
  helper.Equal(0, stats->HP_.GetCurrent(), "testcase2");

  statsComponent.ComponentCleanUp();
  return helper.IsTest();
}
