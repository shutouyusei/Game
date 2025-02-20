#include "BTT_DoAbility.h"
#include "AIController.h"
#include "AbilityManager.h"
#include "GameFramework/Pawn.h"

UBTT_DoAbility::UBTT_DoAbility() {
  NodeName = TEXT("Do Ability");
  bNotifyTick = false;
}

EBTNodeResult::Type
UBTT_DoAbility::ExecuteTask(UBehaviorTreeComponent &OwnerComp,
                            uint8 *NodeMemory) {
  // TODO:EnemyAIの作成
  //  Get the AI controller
  AAIController *AIController = OwnerComp.GetAIOwner();
  if (AIController == nullptr) {
    return EBTNodeResult::Failed;
  }
  // Get the AI pawn
  APawn *AIPawn_ = AIController->GetPawn();
  if (AIPawn_ == nullptr) {
    return EBTNodeResult::Failed;
  }
  // Get the ability manager
  UAbilityManager *abilityManager =
      AIPawn_->FindComponentByClass<UAbilityManager>();
  if (abilityManager == nullptr) {
    return EBTNodeResult::Failed;
  }
  // Use the ability
  abilityManager->Execute(abilityIndex_);
  return EBTNodeResult::Succeeded;
}
