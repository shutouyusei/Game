#include "PlayerStatsComponent.h"
#include "../PlayerStats/PlayerStats.h"

StatsBase *PlayerStatsComponent::stats_ = nullptr;

void PlayerStatsComponent::ComponentSetUp() {
  if (stats_ == nullptr) {
    stats_ = PlayerStatsFactory().CreateStatsBase();
  }
}
void PlayerStatsComponent::ComponentSetUp(FStatsStruct stats) {
  if (stats_ == nullptr) {
    stats_ = PlayerStatsFactory().CreateStatsBase(stats);
  }
}

void PlayerStatsComponent::ComponentCleanUp() {
  delete stats_;
  stats_ = nullptr;
}

