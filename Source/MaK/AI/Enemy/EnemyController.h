#pragma once
#include "../MyController.h"
#include "EnemyBehaviorState.h"

#include "EnemyController.generated.h"

struct FBlackboardKeySelector;
struct FAIStimulus;

UCLASS()
class AEnemyController : public AMyController {
  GENERATED_BODY()
public:
  AEnemyController();

  //NOTE:UObjectデリゲートはUFUNCTION()を使って定義する
  UFUNCTION()
  void OnTargetPerceptionUpdated(AActor *Actor, FAIStimulus Stimulus);

  UFUNCTION(BlueprintCallable)
  void SwitchBehaiviorState(EEnemyBehaiviorState NewState);
  EEnemyBehaiviorState GetState();

protected:
  UPROPERTY(EditAnywhere, Category = "State")
  EEnemyBehaiviorState behaiviorState_;
};
