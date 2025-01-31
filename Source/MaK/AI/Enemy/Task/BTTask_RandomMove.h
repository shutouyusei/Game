#pragma once
#include "BehaviorTree/BTTaskNode.h"
#include "CoreMinimal.h"

#include "BTTask_RandomMove.generated.h"

class APawn;

UCLASS()
class MAK_API UBTTask_RandomMove : public UBTTaskNode {
  GENERATED_BODY()

public:
  UBTTask_RandomMove();

private:
  virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp,
                                          uint8 *NodeMemory) override;

protected:
  virtual void TickTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory,
                        float DeltaSeconds) override;

protected:
  APawn *AIPawn_;
  FVector GoalLocation_;
};
