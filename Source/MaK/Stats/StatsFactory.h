#pragma once
#include "StatsBase.h"
#include "StatsStruct.h"

class StatsFactory {
public:
  virtual StatsBase *CreateStats() = 0;
  virtual StatsBase *CreateStats(FStatsStruct stats) = 0;
  virtual ~StatsFactory() = default;

protected:
  void SetStats(StatsBase *statsBase, FStatsStruct stats);
};
