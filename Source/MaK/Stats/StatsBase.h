#pragma once
#include "StatsStruct.h"

class StatsBase {
public:
  virtual ~StatsBase() = default;

private:
  float HP_;
  float MP_;
  FStatsStruct baseStats_;
};

//
//

class StatsBaseFactory {
public:
  virtual StatsBase *CreateStatsBase() = 0;
  virtual StatsBase *CreateStatsBase(FStatsStruct stats) = 0;
};
