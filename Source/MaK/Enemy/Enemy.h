#pragma once

#include "AbilityManager.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StatusComponent.h"
#include "StatusStruct.h"

#include "Enemy.generated.h"

class UAIPerceptionComponent;

UCLASS()
class AEnemy : public ACharacter {
  GENERATED_BODY()
public:
  AEnemy();
  ~AEnemy();

  TArray<APawn *> *GetTargets();

protected:
  void BeginPlay() override;

public:
  // AI
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
  UAIPerceptionComponent *PerceptionComponent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  UAbilityManager *abilityManager_;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  UStatusComponent *StatusComponent;

  UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "AI")
  TArray<AActor *> targets_;

protected:
  UPROPERTY(EditAnywhere, Category = "Status")
  FStatusStruct status_;

};
