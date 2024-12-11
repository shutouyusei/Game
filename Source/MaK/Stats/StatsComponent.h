
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterStats.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "StatsComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MAK_API UStatsComponent : public UActorComponent {
  GENERATED_BODY()
protected:
public:
  // Sets default values for this component's properties
  UStatsComponent();
  // Set Stats
  void ChangeMaxStats(const FCharacterStats &stats);
  void ChangeCurrentHP(const float stats);
  void ChangeCurrentMP(const float stats);
  // Get Stats
  FCharacterStats GetMaxStats();
  float GetCurrentHP();
  float GetCurrentMP();

protected:
  virtual void BeginPlay() override;

private:
  float CurrentHP;
  float CurrentMP;
  FCharacterStats MaxStats;

public:
private:
};
