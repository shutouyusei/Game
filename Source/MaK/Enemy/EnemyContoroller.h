#pragma once

#include "AIController.h"
#include "CoreMinimal.h"

#include "EnemyContoroller.generated.h"

class UBehaviorTree;
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class MAK_API AEnemyContoroller : public AAIController {
  GENERATED_BODY()
public:
  AEnemyContoroller();

  UFUNCTION(BlueprintCallable, Category = "AI")
  APawn *TargetEnemy();

protected:
  void BeginPlay() override;
  void OnPossess(APawn *InPawn) override;
  void OnUnPossess() override;

public:
  UPROPERTY(EditAnywhere, Category = "BehaviorTree")
  UBehaviorTree *BehaviorTree_;

protected:
  UPROPERTY(BluePrintReadOnly)
  UBehaviorTreeComponent *BehaviorTreeComponent_;

  UPROPERTY(BluePrintReadOnly)
  UBlackboardComponent *BlackboardComponent_;
};
