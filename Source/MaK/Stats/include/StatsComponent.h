#pragma once
#include "../StatsManager.h"
#include "StatsBase.h"
#include "StatsStruct.h"

class StatsComponent {
public:
  StatsComponent();
  ~StatsComponent();
  // set up component
  void ComponentSetUp();
  // clean up component
  void ComponentCleanUp();

  StatsBase *GetPlayerStats() { return stats_; };
  StatsManager *GetStatsManager() { return &statsManager_; };

private:
  static StatsBase *stats_;
  static StatsManager statsManager_;
};
