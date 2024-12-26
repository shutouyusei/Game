#pragma once
#include "StatsStruct.h"

class StatsBase {
private:
  FStatsStruct statsStruct_;
};

//
//

class StatsBaseFactory {
public:
  virtual StatsBase *CreateStatsBase() = 0;
};
