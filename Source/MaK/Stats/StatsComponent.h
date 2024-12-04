
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

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  FCharacterStats BaseStats;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  FCharacterStats MaxStats;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  FCharacterStats CurrentStats;

protected:
  virtual void BeginPlay() override;

public:
};
