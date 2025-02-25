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

AActor *AEnemyController::GetTarget() {
  TArray<AActor *> PerceivedActors;
  PerceptionComponent->GetCurrentlyPerceivedActors(
      UAISense_Sight::StaticClass(), PerceivedActors);
  if (PerceivedActors.Num() > 0) {
    // 現在知覚している中での最優先を探す
    return PerceivedActors[0];
  }
  return nullptr;
}

FAIStimulus AEnemyController::GetStimulusMemory() {
  // MaxAge以上のデータは破棄
  float age  = GetWorld()->GetTimeSeconds() - StimulusMemory_.time;
  UAISenseConfig_Sight *SightConfig =
      PerceptionComponent->GetSenseConfig<UAISenseConfig_Sight>();
  if(age > SightConfig->GetMaxAge()) {
    StimulusMemory_ = {0, FAIStimulus()};
  }
  return StimulusMemory_.Stimulus;
}

void AEnemyController::OnTargetPerceptionUpdated(AActor *Actor,
                                                 FAIStimulus Stimulus) {
  if (Stimulus.WasSuccessfullySensed()) {
    // プレイヤーを感知したら、追跡状態に遷移
    SwitchBehaiviorState(EEnemyBehaiviorState::Combat);
  } else {
    // 視覚でプレイヤーを感知できなくなった
    float time = GetWorld()->GetTimeSeconds();
    StimulusMemory_ = {
      time + Stimulus.GetAge(), Stimulus,
    };
  }
}
