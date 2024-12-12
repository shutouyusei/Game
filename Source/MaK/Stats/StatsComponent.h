// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterStats.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "StatsHandler.h"

#include "StatsComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MAK_API UStatsComponent : public UActorComponent {
  GENERATED_BODY()
protected:
public:
  // Sets default values for this component's properties
  UStatsComponent();

  StatsHandler *GetStatsHandler() { return statsHandler_; }

protected:
  virtual void BeginPlay() override;

private:
  StatsHandler *statsHandler_;

public:
private:
};
