#include "StatsFactory.h"
#include "StatsBase.h"

void StatsFactory::SetStats(StatsBase *statsBase, FStatsStruct stats) {
  statsBase->HP_.SetCurrentParameter(stats.HP);
  statsBase->MP_.SetCurrentParameter(stats.MP);
  //
  statsBase->HP_.SetDefaultParameter(stats.HP);
  statsBase->MP_.SetDefaultParameter(stats.MP);
  statsBase->AD_.SetDefaultParameter(stats.AD);
  statsBase->AP_.SetDefaultParameter(stats.AP);
  statsBase->AR_.SetDefaultParameter(stats.AR);
  statsBase->MR_.SetDefaultParameter(stats.MR);
}
