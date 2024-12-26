#pragma once
#include "../StatsBase.h"

class PlayerStats : public StatsBase {};

//
//

class PlayerStatsFactory : public StatsBaseFactory {
public:
  StatsBase *CreateStatsBase() override { return new PlayerStats(); }
};
