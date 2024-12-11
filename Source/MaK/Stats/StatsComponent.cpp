// Fill out your copyright notice in the Description page of Project Settings.

#include "StatsComponent.h"

UStatsComponent::UStatsComponent() {
  // Set this component to be initialized when the game starts, and to be ticked
  // every frame.  You can turn these features off to improve performance if you
  // don't need them.
}

// Called when the game starts
void UStatsComponent::BeginPlay() {
  Super::BeginPlay();

  // ...
}

// Set Stats
void UStatsComponent::ChangeMaxStats(const FCharacterStats &stats) {
  MaxStats = stats;
  if (CurrentHP > MaxStats.HP) {
    CurrentHP = MaxStats.HP;
  }
  if (CurrentMP > MaxStats.MP) {
    CurrentMP = MaxStats.MP;
  }
}

void UStatsComponent::ChangeCurrentHP(const float stats) {
  if (CurrentHP + stats >= MaxStats.HP) {
    CurrentHP = MaxStats.HP;
  } else {
    CurrentHP += stats;
  }
}

void UStatsComponent::ChangeCurrentMP(const float stats) {
  if (CurrentMP + stats >= MaxStats.MP) {
    CurrentMP = MaxStats.MP;
  } else {
    CurrentMP += stats;
  }
}
// Get Stats
float UStatsComponent::GetCurrentHP() { return CurrentHP; }
float UStatsComponent::GetCurrentMP() { return CurrentMP; }
FCharacterStats UStatsComponent::GetMaxStats() { return MaxStats; }
