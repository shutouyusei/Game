#include "AIController.h"
#include "BTTask_RandomMove.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"

UBTTask_RandomMove::UBTTask_RandomMove() { NodeName = TEXT("Random Move"); }

EBTNodeResult::Type
UBTTask_RandomMove::ExecuteTask(UBehaviorTreeComponent &OwnerComp,
                                uint8 *NodeMemory) {
  // Get the AI controller
  AAIController *AIController = OwnerComp.GetAIOwner();
  if (AIController == nullptr) {
    return EBTNodeResult::Failed;
  }
  // Get the AI pawn
  AIPawn_ = AIController->GetPawn();
  if (AIPawn_ == nullptr) {
    return EBTNodeResult::Failed;
  }
  // Get the AI movement component
  UCharacterMovementComponent *MovementComponent =
      AIPawn_->FindComponentByClass<UCharacterMovementComponent>();
  if (MovementComponent == nullptr) {
    return EBTNodeResult::Failed;
  }
  // Get the AI's current location
  FVector CurrentLocation = AIPawn_->GetActorLocation();
  // Generate a random location
  GoalLocation_ = FVector(FMath::RandRange(-500.0f, 500.0f),
                          FMath::RandRange(-500.0f, 500.0f), 0.0f);
  // Move the AI to the random location
  return EBTNodeResult::InProgress;
}

void UBTTask_RandomMove::TickTask(UBehaviorTreeComponent &OwnerComp,
                                  uint8 *NodeMemory, float DeltaSeconds) {
  UE_LOG(LogTemp, Warning, TEXT("TickTask"));
  AIPawn_->AddMovementInput((GoalLocation_).GetSafeNormal());
  FVector CurrentLocation = AIPawn_->GetActorLocation();
  if (FVector::Dist(CurrentLocation, GoalLocation_) < 100.0f) {
    // Finish the task
    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
  }
}
