#pragma once
#include "StatsBase.h"

class StatsFactory {
public:
  virtual StatsBase *CreateStats() = 0;
  virtual ~StatsFactory() = default;
};
