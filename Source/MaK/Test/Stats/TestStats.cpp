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

bool operator!=(FStatsStruct &a, FStatsStruct &b) { return !(a == b); }

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlayerStatsComponentTest,
                                 "Stats.PlayerStatsComponentTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FPlayerStatsComponentTest::RunTest(const FString &Parameters) {
  TestHelper helper;
  // Stats Component Set Up
  FStatsStruct testcase = {100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0};
  StatsComponent statsComponent;
  FStatsStruct stat = statsComponent.GetStats();
  statsComponent.ComponentSetUp(testcase);
  helper.Equal(stat, testcase, "testcase1");

  StatsBase *stats = statsComponent.Get();
  stats->MP_.Increase(10);
  float mp = stats->MP_.Get();
  float answer = 110;
  helper.Equal(mp, answer, "testcase2");

  stats->MP_.Decrease(10);
  mp = stats->MP_.Get();
  answer = 100;
  helper.Equal(mp, answer, "testcase3");

  stats->MP_.SetRatio(1.1);
  mp = stats->MP_.Get();
  answer = 120;
  helper.Equal(answer, mp, "testcase4");
  // HP test
  float hp = stats->HP_.GetCurrent();
  answer = 100;
  helper.Equal(answer, hp, "testcase5");

  stats->HP_.Damage(10);
  hp = stats->HP_.Get();
  answer = 100;
  helper.Equal(answer, hp, "testcase6");
  hp = stats->HP_.GetCurrent();
  answer = 90;
  helper.Equal(answer, hp, "testcase7");

  stats->HP_.Heal(100);
  hp = stats->HP_.Get();
  answer = 100;
  helper.Equal(answer, hp, "testcase8");
  hp = stats->HP_.GetCurrent();
  helper.Equal(answer, hp, "testcase9");

  statsComponent.ComponentCleanUp();
  return helper.IsTest();
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FStatsComponentTest, "Stats.DeathNotifyTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FStatsComponentTest::RunTest(const FString &Parameters) {
  TestHelper helper;
  // Stats Component Set Up
  FStatsStruct testcase = {100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0};
  StatsComponent statsComponent;
  statsComponent.ComponentSetUp(testcase);
  FStatsStruct stat = statsComponent.GetStats();
  helper.Equal(stat, testcase, "testcase1");
  StatsBase *stats = statsComponent.Get();

  stats->HP_.Damage(150);
  float answer = 0;
  float hp = stats->HP_.GetCurrent();
  helper.Equal(answer, hp, "testcase2");

  statsComponent.ComponentCleanUp();
  return helper.IsTest();
}
