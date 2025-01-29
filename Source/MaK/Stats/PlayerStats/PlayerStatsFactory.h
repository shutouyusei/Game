#pragma once
#include "StatsFactory.h"
#include "StatsStruct.h"

class PlayerStatsFactory : public StatsFactory {
public:
  PlayerStatsFactory();
  virtual StatsBase *CreateStats() override;
  virtual StatsBase *CreateStats(FStatsStruct stats) override;
  ~PlayerStatsFactory() override;

private:
  void SetDeathCallback(StatsBase *statsBase);
};
