#pragma once
#include "../AIMemory.h"
#include "../MyController.h"
#include "EnemyBehaviorState.h"
#include "Perception/AIPerceptionTypes.h"

#include "EnemyController.generated.h"
struct FBlackboardKeySelector;

UCLASS()
class AEnemyController : public AMyController {
  GENERATED_BODY()
public:
  AEnemyController();

  // NOTE:UObjectデリゲートはUFUNCTION()を使って定義する
  UFUNCTION()
  void OnTargetPerceptionUpdated(AActor *Actor, FAIStimulus Stimulus);

  UFUNCTION(BlueprintCallable)
  void SwitchBehaiviorState(EEnemyBehaiviorState NewState);

  UFUNCTION(BlueprintCallable)
  void Death();

  EEnemyBehaiviorState GetState();

protected:
  UPROPERTY()
  FAIMemory StimulusMemory_;
  UPROPERTY(EditAnywhere, Category = "State")
  EEnemyBehaiviorState behaiviorState_;
};
