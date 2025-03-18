#pragma once

#include "../EnemyBehaviorState.h"
#include "BehaviorTree/BTDecorator.h"
#include "CoreMinimal.h"

#include "BTD_CheckState.generated.h"

UCLASS()
class UBTD_CheckState : public UBTDecorator {
  GENERATED_BODY()
public:
  UBTD_CheckState();
  virtual bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp,
                                          uint8 *NodeMemory) const override;

protected:
  // Target State Key
  UPROPERTY(EditAnywhere, Category = "State")
  EEnemyBehaiviorState targetState_;
};
