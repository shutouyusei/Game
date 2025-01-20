#pragma once
#include "../StatsStruct.h"
#include "StatsBase.h"

class StatsFactory {
public:
  virtual StatsBase *CreateStats();
  virtual StatsBase *CreateStats(FStatsStruct stats);
  virtual ~StatsFactory() = default;

protected:
  void SetStats(StatsBase *statsBase, FStatsStruct stats);
};
