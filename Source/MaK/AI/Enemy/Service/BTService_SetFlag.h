#pragma once

#include "BehaviorTree/BTService.h"
#include "CoreMinimal.h"

#include "BTService_SetFlag.generated.h"

UCLASS()
class UBTService_SetFlag : public UBTService {
  GENERATED_BODY()
public:
  UBTService_SetFlag();

protected:
  virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory,
                        float DeltaSeconds) override;

private:
  UPROPERTY(EditAnywhere, Category = "Blackboard")
  FBlackboardKeySelector KeyName;
};
