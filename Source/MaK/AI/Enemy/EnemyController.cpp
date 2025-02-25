#include "EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyBehaviorState.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemyController::AEnemyController() : AMyController() {
  // Constructor
  behaiviorState_ = EEnemyBehaiviorState::Idle;
  PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(
      TEXT("PerceptionComponent"));
  // 視覚
  UAISenseConfig_Sight *SightConfig =
      CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
  PerceptionComponent->ConfigureSense(*SightConfig);

  // 知覚イベントのコールバック
  PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(
      this, &AEnemyController::OnTargetPerceptionUpdated);
};

void AEnemyController::SwitchBehaiviorState(EEnemyBehaiviorState NewState) {
  behaiviorState_ = NewState;
};

EEnemyBehaiviorState AEnemyController::GetState() { return behaiviorState_; }

void AEnemyController::OnTargetPerceptionUpdated(AActor *Actor,
                                                 FAIStimulus Stimulus) {
  if (Stimulus.WasSuccessfullySensed()) {
    // プレイヤーを感知したら、追跡状態に遷移
    SwitchBehaiviorState(EEnemyBehaiviorState::Combat);
    // Add Blackboard
    BlackboardComponent_->SetValueAsObject("Target", Actor);
  }
}
