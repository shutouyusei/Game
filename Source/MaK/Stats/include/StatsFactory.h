#pragma once
#include "../StatsStruct.h"
#include "StatsBase.h"

class StatsFactory {
public:
  virtual StatsBase *CreateStats();
  virtual StatsBase *CreateStats(FStatsStruct stats);
  virtual void DestroyStats(StatsBase *statsBase);
  virtual ~StatsFactory() = default;

protected:
  void SetStats(StatsBase *statsBase, FStatsStruct stats);
};
