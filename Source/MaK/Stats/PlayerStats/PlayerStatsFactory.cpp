#include "PlayerStatsFactory.h"

PlayerStatsFactory::PlayerStatsFactory() {}

StatsBase *PlayerStatsFactory::CreateStats() {
  StatsBase *statsBase = new StatsBase();
  // TODO:set stats from save data
  statsBase->HP_.SetCurrentParameter(100.0f);
  statsBase->MP_.SetCurrentParameter(50.0f);
  //
  statsBase->HP_.SetDefaultParameter(100.0f);
  statsBase->MP_.SetDefaultParameter(50.0f);
  statsBase->AD_.SetDefaultParameter(10.0f);
  statsBase->AP_.SetDefaultParameter(20.0f);
  statsBase->AR_.SetDefaultParameter(5.0f);
  statsBase->MR_.SetDefaultParameter(5.0f);
  SetDeathCallback(statsBase);
  return statsBase;
}

StatsBase *PlayerStatsFactory::CreateStats(FStatsStruct stats) {
  StatsBase *statsBase = new StatsBase();
  statsBase->HP_.SetCurrentParameter(stats.HP);
  statsBase->MP_.SetCurrentParameter(stats.MP);
  //
  statsBase->HP_.SetDefaultParameter(stats.HP);
  statsBase->MP_.SetDefaultParameter(stats.MP);
  statsBase->AD_.SetDefaultParameter(stats.AD);
  statsBase->AP_.SetDefaultParameter(stats.AP);
  statsBase->AR_.SetDefaultParameter(stats.AR);
  statsBase->MR_.SetDefaultParameter(stats.MR);
  SetDeathCallback(statsBase);
  return statsBase;
}

PlayerStatsFactory::~PlayerStatsFactory() {}

void PlayerStatsFactory::SetDeathCallback(StatsBase *statsBase) {
  statsBase->HP_.SetDeathCallback(
      []() { UE_LOG(LogTemp, Warning, TEXT("Player is dead")); });
}
