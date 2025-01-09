#include "StatsComponent.h"
#include "../PlayerStats/PlayerStatsFactory.h"
#include "CoreMinimal.h"

StatsBase *StatsComponent::stats_ = nullptr;

StatsComponent::StatsComponent() {}

StatsComponent::~StatsComponent() {}

void StatsComponent::ComponentSetUp() {
  if (stats_ != nullptr) {
    return;
  }
  stats_ = PlayerStatsFactory().CreateStats();
}


void StatsComponent::ComponentCleanUp() { delete stats_; }
