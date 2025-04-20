#include "NormalSwordAttack.h"
#include "../../AnimatedAttack.h"

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

bool UNormalSwordAttack::get_in_air() const {
  // judge is in air
  return false;
}
