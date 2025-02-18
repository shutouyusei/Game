#pragma once

#include "AIController.h"
#include "CoreMinimal.h"

#include "MyController.generated.h"

class UBehaviorTree;
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class AMyController : public AAIController {
  GENERATED_BODY()
public:
  AMyController();

protected:
  void BeginPlay() override;
  void OnPossess(APawn *InPawn) override;
  void OnUnPossess() override;

protected:
  UPROPERTY(EditAnywhere, Category = "BehaviorTree")
  UBehaviorTree *BehaviorTree_;

  UPROPERTY(BluePrintReadOnly)
  UBehaviorTreeComponent *BehaviorTreeComponent_;

  UPROPERTY(BluePrintReadOnly)
  UBlackboardComponent *BlackboardComponent_;
};
