#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "../EnemyBehaviorState.h"

#include "BTDecorator_CheckState.generated.h"

UCLASS()
class MAK_API UBTDecorator_CheckState : public UBTDecorator {
  GENERATED_BODY()
public:
  UBTDecorator_CheckState();
  virtual  bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const override;
protected:
  UPROPERTY(EditAnywhere, Category = "State")
  EEnemyBehaiviorState TargetState_;
};
