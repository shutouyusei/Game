#include "EnemyContoroller.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemyContoroller::AEnemyContoroller() : AMyController() {
  // Constructor
  BehaiviorState_ = EEnemyBehaiviorState::Idle;
};

void AEnemyContoroller::SwitchBehaiviorState(EEnemyBehaiviorState NewState) {
  BlackboardComponent_->SetValueAsEnum("State", (uint8)NewState);
};
