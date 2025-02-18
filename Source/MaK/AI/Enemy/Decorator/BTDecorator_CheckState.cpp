#include "BTDecorator_CheckState.h"
#include "../EnemyContoroller.h"

UBTDecorator_CheckState::UBTDecorator_CheckState() {
  NodeName = TEXT("Check State");
}

bool UBTDecorator_CheckState::CalculateRawConditionValue(
    UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const {
  AEnemyContoroller *enemyController = Cast<AEnemyContoroller>(OwnerComp.GetAIOwner());
  if(enemyController == nullptr) {
    return false;
  }
  if(enemyController->GetBehaiviorState() == TargetState_) {
    return true;
  }
  return false;
}
