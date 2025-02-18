#include "EnemyContoroller.h"
#include "Enemy.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEnemyContoroller::AEnemyContoroller() {
  // Constructor
  BehaviorTreeComponent_ =
      CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorTreeComponent");
  BlackboardComponent_ =
      CreateDefaultSubobject<UBlackboardComponent>("BlackboardComponent");
}

void AEnemyContoroller::BeginPlay() {
  // Called when the game starts or when spawned
  Super::BeginPlay();
};

void AEnemyContoroller::OnPossess(APawn *InPawn) {
  Super::OnPossess(InPawn);

  if (BehaviorTree_ == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("BehaviorTree is nullptr"));
    return;
  }
  BlackboardComponent_->InitializeBlackboard(*BehaviorTree_->BlackboardAsset);
  BehaviorTreeComponent_->StartTree(*BehaviorTree_);
};

void AEnemyContoroller::OnUnPossess() {
  Super::OnUnPossess();
  BehaviorTreeComponent_->StopTree();
};

APawn *AEnemyContoroller::TargetEnemy() {
  AEnemy *owner = Cast<AEnemy>(GetPawn());
  // TODO:ターゲットアルゴリズム
  if(owner->targets_.Num() > 0){
    APawn *target = Cast<APawn>(owner->targets_[0]);
    return target;
  }
  return nullptr;
};
