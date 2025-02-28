#include "BTD_CheckState.h"
#include "../EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTD_CheckState::UBTD_CheckState() { NodeName = TEXT("Check State"); }

bool UBTD_CheckState::CalculateRawConditionValue(
    UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const {
  // Get Blackboard Component
  AAIController *controller = OwnerComp.GetAIOwner();
  AEnemyController *enemyController = Cast<AEnemyController>(controller);
  if (enemyController == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("EnemyController is nullptr"));
    return false;
  }
  if (targetState_ == enemyController->GetState()) {
    return true;
  }
  return false;
}
