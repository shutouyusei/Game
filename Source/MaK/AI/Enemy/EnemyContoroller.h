#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "EnemyBehaviorState.h"

#include "EnemyContoroller.generated.h"

class UBehaviorTree;
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class MAK_API AEnemyContoroller : public AAIController {
  GENERATED_BODY()
public:
  AEnemyContoroller();

  UFUNCTION(BlueprintCallable)
  void SwitchBehaiviorState(EEnemyBehaiviorState NewState);
  UFUNCTION(BlueprintCallable)
  EEnemyBehaiviorState GetBehaiviorState() const { return BehaiviorState_; }

protected:
  void BeginPlay() override;
  void OnPossess(APawn *InPawn) override;
  void OnUnPossess() override;

protected:
  UPROPERTY(EditAnywhere, Category = "State")
  EEnemyBehaiviorState BehaiviorState_;

  UPROPERTY(EditAnywhere, Category = "BehaviorTree")
  UBehaviorTree *BehaviorTree_;

  UPROPERTY(BluePrintReadOnly)
  UBehaviorTreeComponent *BehaviorTreeComponent_;

  UPROPERTY(BluePrintReadOnly)
  UBlackboardComponent *BlackboardComponent_;
};
