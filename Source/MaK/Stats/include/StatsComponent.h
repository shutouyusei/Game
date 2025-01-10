#pragma once
#include "../StatsStruct.h"
#include "StatsBase.h"

class StatsComponent {
public:
  StatsComponent();
  ~StatsComponent();
  // set up component
  void ComponentSetUp();
  // clean up component
  void ComponentCleanUp();

  StatsBase *Get() { return stats_; };

private:
  static StatsBase *stats_;
};
