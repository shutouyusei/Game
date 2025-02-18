#include "BTService_SetFlag.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_SetFlag::UBTService_SetFlag() { NodeName = "SetFlag"; }

void UBTService_SetFlag::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory,
                                  float DeltaSeconds) {
  Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
  UBlackboardComponent *BlackboardComp = OwnerComp.GetBlackboardComponent();
  if (BlackboardComp) {
    BlackboardComp->SetValueAsBool(KeyName.SelectedKeyName, true);
  }
}
