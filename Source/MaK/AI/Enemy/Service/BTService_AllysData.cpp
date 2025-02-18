#include "BTService_AllysData.h"
#include "../EnemyContoroller.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_AllysData::UBTService_AllysData() { NodeName = "AllysData"; }

void UBTService_AllysData::TickNode(UBehaviorTreeComponent &OwnerComp,
                                    uint8 *NodeMemory, float DeltaSeconds) {
  Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
  AEnemyContoroller *controller =
      Cast<AEnemyContoroller>(OwnerComp.GetAIOwner());
  if (controller == nullptr) {
    return;
  }
  UBlackboardComponent *blackboard = OwnerComp.GetBlackboardComponent();
  //
}
