#include "BTT_EnemyMove.h"
#include "../EnemyController.h"

UBTT_EnemyMove::UBTT_EnemyMove() { NodeName = TEXT("EnemyMove"); }

EBTNodeResult::Type
UBTT_EnemyMove::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) {
  // Get the AI controller
  AEnemyController *enemyController =
      Cast<AEnemyController>(OwnerComp.GetAIOwner());

  return EBTNodeResult::Succeeded;
}

void UBTT_EnemyMove::TickTask(UBehaviorTreeComponent &OwnerComp,
                              uint8 *NodeMemory, float DeltaSeconds) {
  Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
}
