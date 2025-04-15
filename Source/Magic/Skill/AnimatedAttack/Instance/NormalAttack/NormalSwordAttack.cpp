#include "NormalSwordAttack.h"
#include "../../AnimatedAttack.h"

void UNormalSwordAttack::Activate() {
  //  スキルの実行
  // TODO:if in air
  // if can combo
  AttackonGround(combo_);
  combo_ = (combo_ + 1) % (level_ + 1);
}

void UNormalSwordAttack::AttackonGround(int32 combo) {
  if (combo < attack_on_ground_modules_.Num()) {
    attack_on_ground_modules_[combo]->Attack();
  } else {
    // Handle the case where combo is out of bounds
    UE_LOG(LogTemp, Warning, TEXT("Combo index out of bounds: %d"), combo);
  }
}

void UNormalSwordAttack::AttackinAir(int32 combo) {
  attack_in_air_modules_[combo]->Attack();
}
