#pragma once
#include "../StatsResource.h"

class StatsBase {
public:
  StatsBase();
  virtual ~StatsBase();

public:
  StatsResource HP_;
  StatsResource MP_;
  StatsParameter AD_;
  StatsParameter AP_;
  StatsParameter AR_;
  StatsParameter MR_;
};
