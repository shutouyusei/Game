#include "BTS_AllysData.h"
#include "../EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTS_AllysData::UBTS_AllysData() { NodeName = "AllysData"; }

void UBTS_AllysData::TickNode(UBehaviorTreeComponent &OwnerComp,
                              uint8 *NodeMemory, float DeltaSeconds) {
  Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
  AEnemyController *controller = Cast<AEnemyController>(OwnerComp.GetAIOwner());
  if (controller == nullptr) {
    return;
  }
  UBlackboardComponent *blackboard = OwnerComp.GetBlackboardComponent();
  //
}
