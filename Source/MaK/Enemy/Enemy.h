#pragma once

#include "AbilityManager.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StatsStruct.h"

#include "Enemy.generated.h"

class UAIPerceptionComponent;
class UStatsComponent;

UCLASS()
class AEnemy : public ACharacter {
  GENERATED_BODY()
public:
  AEnemy();
  ~AEnemy();

protected:
  void BeginPlay() override;

public:
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
  UAIPerceptionComponent *PerceptionComponent;

  UPROPERTY(EditAnywhere, Category = "Ability")
  UAbilityManager *abilityManager_;

  UPROPERTY(EditAnywhere, Category = "Stats")
  UStatsComponent *StatsComponent;

protected:
  UPROPERTY(EditAnywhere, Category = "Stats")
  FStatsStruct stats_;
};
