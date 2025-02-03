#include "BTTask_DoAbility.h"
#include "AIController.h"
#include "AbilityManager.h"
#include "GameFramework/Pawn.h"

UBTTask_DoAbility::UBTTask_DoAbility() {
  NodeName = TEXT("Do Ability");
  bNotifyTick = false;
}

EBTNodeResult::Type
UBTTask_DoAbility::ExecuteTask(UBehaviorTreeComponent &OwnerComp,
                               uint8 *NodeMemory) {
  // Get the AI controller
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
  AbilityManager_ = AIPawn_->FindComponentByClass<UAbilityManager>();
  if (AbilityManager_ == nullptr) {
    return EBTNodeResult::Failed;
  }
  // Use the ability
  AbilityManager_->ExecuteAbility(abilityIndex_);
  return EBTNodeResult::Succeeded;
}
