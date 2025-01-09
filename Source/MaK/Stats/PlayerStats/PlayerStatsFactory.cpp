#include "PlayerStatsFactory.h"

PlayerStatsFactory::PlayerStatsFactory() {}

StatsBase *PlayerStatsFactory::CreateStats() {
  StatsBase *statsBase = new StatsBase();
  // TODO:set stats from save data
  // SetStats()
  SetDeathCallback(statsBase);
  return statsBase;
}

StatsBase *PlayerStatsFactory::CreateStats(FStatsStruct stats) {
  StatsBase *statsBase = new StatsBase();
  SetStats(statsBase, stats);
  SetDeathCallback(statsBase);
  return statsBase;
}

PlayerStatsFactory::~PlayerStatsFactory() {}

void PlayerStatsFactory::SetDeathCallback(StatsBase *statsBase) {
  statsBase->HP_.SetDeathCallback(
      []() { UE_LOG(LogTemp, Warning, TEXT("Player is dead")); });
}
