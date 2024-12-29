#pragma once
#include "../StatsBase.h"
#include "../StatsStruct.h"

class StatsComponent {
public:
  StatsComponent();
  ~StatsComponent();
  // set up component
  void ComponentSetUp();
  void ComponentSetUp(FStatsStruct stats);
  // clean up component
  void ComponentCleanUp();
  FStatsStruct GetStats();

  StatsBase *Get() { return stats_; };

private:
  void SetDeathCallback();
  static StatsBase *stats_;
};
