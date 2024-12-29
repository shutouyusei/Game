#pragma once
#include "../StatsFactory.h"

class PlayerStatsFactory : public StatsFactory {
public:
  PlayerStatsFactory();
  virtual StatsBase *CreateStats() override;
  ~PlayerStatsFactory() override;
};
