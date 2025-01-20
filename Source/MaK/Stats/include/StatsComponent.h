#pragma once
#include "../StatsStruct.h"
#include "StatsBase.h"
#include "../StatsManager.h"

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
