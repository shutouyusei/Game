#pragma once

#include "AbilityManager.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StatusStruct.h"

#include "Enemy.generated.h"

class UAIPerceptionComponent;
class UStatusComponent;

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

  UPROPERTY(EditAnywhere, Category = "Status")
  UStatusComponent *StatusComponent;

protected:
  UPROPERTY(EditAnywhere, Category = "Status")
  FStatusStruct status_;
};
