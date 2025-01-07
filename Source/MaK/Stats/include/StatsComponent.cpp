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
  SetDeathCallback();
}

void StatsComponent::ComponentSetUp(FStatsStruct stats) {
  if (stats_ != nullptr) {
    return;
  }
  stats_ = PlayerStatsFactory().CreateStats(stats);
  SetDeathCallback();
}

void StatsComponent::SetDeathCallback() {
  stats_->HP_.SetDeathCallback(
      []() { UE_LOG(LogTemp, Warning, TEXT("Player is dead")); });
}

void StatsComponent::ComponentCleanUp() { delete stats_; }

FStatsStruct StatsComponent::GetStats() {
  FStatsStruct stats = {
      /* HP */ stats_->HP_.Get(),
      /* MP */ stats_->MP_.Get(),
      /* AD */ stats_->AD_.Get(),
      /* AP */ stats_->AP_.Get(),
      /* AR */ stats_->AR_.Get(),
      /* MR */ stats_->MR_.Get(),
  };
  return stats;
}
