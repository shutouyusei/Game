#pragma once

#include "../EnemyBehaviorState.h"
#include "BehaviorTree/BTDecorator.h"
#include "CoreMinimal.h"

#include "BTDecorator_CheckState.generated.h"

UCLASS()
class MAK_API UBTDecorator_CheckState : public UBTDecorator {
  GENERATED_BODY()
public:
  UBTDecorator_CheckState();
  virtual bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp,
                                          uint8 *NodeMemory) const override;

protected:
  // Target State Key
  UPROPERTY(EditAnywhere, Category = "State")
  EEnemyBehaiviorState TargetState_;
  // Black Board Key
  UPROPERTY(EditAnywhere, Category = "State")
  FBlackboardKeySelector TargetStateKey;
};
