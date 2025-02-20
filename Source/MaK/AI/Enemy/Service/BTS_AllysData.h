#pragma once

#include "BehaviorTree/BTService.h"
#include "CoreMinimal.h"

#include "BTS_AllysData.generated.h"

UCLASS()
class UBTS_AllysData : public UBTService {
  GENERATED_BODY()
public:
  UBTS_AllysData();

protected:
  virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory,
                        float DeltaSeconds) override;

private:
  UPROPERTY(EditAnywhere, Category = "Blackboard")
  FBlackboardKeySelector allysData_;
};
