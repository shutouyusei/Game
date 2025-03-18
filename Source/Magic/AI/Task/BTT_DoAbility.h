#pragma once
#include "BehaviorTree/BTTaskNode.h"
#include "CoreMinimal.h"

#include "BTT_DoAbility.generated.h"

class UAbilityManager;

UCLASS()
class UBTT_DoAbility : public UBTTaskNode {
  GENERATED_BODY()
public:
  UBTT_DoAbility();

  UPROPERTY(EditAnywhere, Category = "Ability")
  int abilityIndex_ = 0;

private:
  virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp,
                                          uint8 *NodeMemory) override;
};
