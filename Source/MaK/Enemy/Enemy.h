#pragma once

#include "AbilityManager.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StatusStruct.h"
#include "StatusComponent.h"

#include "Enemy.generated.h"

class UAIPerceptionComponent;
class UAiSenseConfig_Sight;

UCLASS()
class AEnemy : public ACharacter {
  GENERATED_BODY()
public:
  AEnemy();
  ~AEnemy();

protected:
  void BeginPlay() override;
  //XXX:エラー直してね
  void OnTargetPerceptionUpdated(AActor *actor, FAIStimulus stimulus);

public:
  //AI
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
  UAIPerceptionComponent *PerceptionComponent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception")
  UAISenseConfig_Sight *SightConfig;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  UAbilityManager *abilityManager_;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  UStatusComponent *StatusComponent;


protected:
  UPROPERTY(EditAnywhere, Category = "Status")
  FStatusStruct status_;
};
