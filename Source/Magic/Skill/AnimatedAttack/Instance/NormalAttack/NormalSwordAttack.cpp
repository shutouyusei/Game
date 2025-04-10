#include "NormalSwordAttack.h"
#include "../../AnimatedAttack.h"

void UNormalSwordAttack::Activate() {
  //  スキルの実行
  AttackonGround(combo_);
  combo_ = (combo_ + 1) % (skill_data_.level + 1);
}

void UNormalSwordAttack::AttackonGround(int32 combo){
  attack_on_ground_modules_[combo]->Attack();
}

void UNormalSwordAttack::AttackinAir(int32 combo){
  attack_in_air_modules_[combo]->Attack();
}
