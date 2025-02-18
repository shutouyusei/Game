#pragma once

#include "BehaviorTree/BTService.h"
#include "CoreMinimal.h"

#include "BTService_AllysData.generated.h"

UCLASS()
class UBTService_AllysData : public UBTService {
  GENERATED_BODY()
public:
  UBTService_AllysData();

protected:
  virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory,
                        float DeltaSeconds) override;

private:
  UPROPERTY(EditAnywhere, Category = "Blackboard")
  FBlackboardKeySelector allysData_;
};
