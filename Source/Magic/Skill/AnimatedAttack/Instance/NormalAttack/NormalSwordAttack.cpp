#include "NormalSwordAttack.h"
#include "../../AnimatedAttack.h"
#include "GameFramework/CharacterMovementComponent.h"

//TODO:Review the conditions for the combo
void UNormalSwordAttack::Activate() {
  //  スキルの実行
  if (get_in_air()) {
    AttackinAir(combo_);
  } else {
    AttackonGround(combo_);
  }
  combo_ = (combo_ + 1) % (level_ + 1);
}

void UNormalSwordAttack::EndCombo() {
  // Reset the combo counter
  combo_ = 0;
}

void UNormalSwordAttack::AttackonGround(int32 combo) {
  attack_on_ground_modules_[combo]->Attack();
}


void UNormalSwordAttack::AttackinAir(int32 combo) {
  attack_in_air_modules_[combo]->Attack();
}

void UNormalSwordAttack::Jump(ACharacter *character) {
  // Jump in combo 4
  const FVector upper_regist_vector = FVector(0,0,700);
  movement_component_->AddImpulse(upper_regist_vector,true);
}

void UNormalSwordAttack::Float(ACharacter *character){
  const FVector upper_regist_vector = FVector(0,0,400);
  movement_component_->AddImpulse(upper_regist_vector,true);
}

bool UNormalSwordAttack::get_in_air() const {
  // judge is in air
  return movement_component_->IsFalling();
}
