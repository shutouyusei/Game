#include "MyController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"

AMyController::AMyController() {
  // Constructor
  BehaviorTreeComponent_ =
      CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorTreeComponent");
  BlackboardComponent_ =
      CreateDefaultSubobject<UBlackboardComponent>("BlackboardComponent");
}

void AMyController::BeginPlay() {
  // Called when the game starts or when spawned
  Super::BeginPlay();
};

void AMyController::OnPossess(APawn *InPawn) {
  Super::OnPossess(InPawn);

  if (BehaviorTree_ == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("BehaviorTree is nullptr"));
    return;
  }
  BlackboardComponent_->InitializeBlackboard(*BehaviorTree_->BlackboardAsset);
  BehaviorTreeComponent_->StartTree(*BehaviorTree_);
};

void AMyController::OnUnPossess() {
  Super::OnUnPossess();
  BehaviorTreeComponent_->StopTree();
};

