#pragma once
#include "BehaviorTree/BTTaskNode.h"
#include "CoreMinimal.h"

#include "BTTask_DoAbility.generated.h"

class UAbilityManager;

UCLASS()
class MAK_API UBTTask_DoAbility : public UBTTaskNode {
  GENERATED_BODY()
public:
  UBTTask_DoAbility();

  UPROPERTY(EditAnywhere, Category = "Ability")
  int abilityIndex_;

private:
  virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp,
                                          uint8 *NodeMemory) override;

private:
  UAbilityManager *AbilityManager_;
};
