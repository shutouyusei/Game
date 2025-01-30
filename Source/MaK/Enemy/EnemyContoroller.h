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

  UPROPERTY(EditAnywhere, Category = "BehaviorTree")
  UBehaviorTree *BehaviorTree_;

  UFUNCTION(BlueprintCallable)
  void SetPlayer(APawn *Player);

protected:
  UPROPERTY(BluePrintReadOnly)
  UBehaviorTreeComponent *BehaviorTreeComponent_;

  UPROPERTY(BluePrintReadOnly)
  UBlackboardComponent *BlackboardComponent_;
  

protected:
  void BeginPlay() override;
  void OnPossess(APawn *InPawn) override;
  void OnUnPossess() override;
};
