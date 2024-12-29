#include "PlayerStatsFactory.h"

PlayerStatsFactory::PlayerStatsFactory() {}

StatsBase *PlayerStatsFactory::CreateStats() {
  StatsBase *stats = new StatsBase();
  //TODO:set stats from save data
  stats->HP_.SetCurrent(100.0f);
  stats->MP_.SetCurrent(50.0f);
  //
  stats->HP_.SetDefault(100.0f);
  stats->MP_.SetDefault(50.0f);
  stats->AD_.SetDefault(10.0f);
  stats->AP_.SetDefault(20.0f);
  stats->AR_.SetDefault(5.0f);
  stats->MR_.SetDefault(5.0f);
  return stats;
}

StatsBase *PlayerStatsFactory::CreateStats(FStatsStruct stats) {
  StatsBase *statsBase = new StatsBase();
  statsBase->HP_.SetCurrent(stats.HP);
  statsBase->MP_.SetCurrent(stats.MP);
  statsBase->AD_.SetDefault(stats.AD);
  statsBase->AP_.SetDefault(stats.AP);
  statsBase->AR_.SetDefault(stats.AR);
  statsBase->MR_.SetDefault(stats.MR);
  return statsBase;
}


PlayerStatsFactory::~PlayerStatsFactory() {}

