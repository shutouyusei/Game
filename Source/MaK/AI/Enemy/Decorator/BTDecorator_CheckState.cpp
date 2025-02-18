#include "BTDecorator_CheckState.h"
#include "../EnemyContoroller.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_CheckState::UBTDecorator_CheckState() {
  NodeName = TEXT("Check State");
}

bool UBTDecorator_CheckState::CalculateRawConditionValue(
    UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const {
  // Get Blackboard Component
  AAIController *Controller = OwnerComp.GetAIOwner();
  if (Controller == nullptr) {
    return false;
  }
  UBlackboardComponent *BlackboardComp = Controller->GetBlackboardComponent();
  if (BlackboardComp == nullptr) {
    return false;
  }
  // Get Value from Blackboard
  EEnemyBehaiviorState State = (EEnemyBehaiviorState)(BlackboardComp->GetValueAsEnum(TargetStateKey.SelectedKeyName));

  if (State == TargetState_) {
    return true;
  }
  return false;
}
