#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "EnemyContoroller.generated.h"

/**
 *
 */
UCLASS()
class MAK_API AEnemyContoroller : public AAIController {
  GENERATED_BODY()
public:
  AEnemyContoroller();
  void SetPlayer(APawn *player);
  UPROPERTY(EditAnywhere, Category = "BehaviorTree")
  UBehaviorTree *BehaviorTree_;
protected:
  UPROPERTY()
  UBehaviorTreeComponent *BehaviorTreeComponent_;

  UPROPERTY()
  UBlackboardComponent *BlackboardComponent_;

protected:
  void BeginPlay() override;
  void OnPossess(APawn *InPawn) override;
  void OnUnPossess() override;
};
