#include "SwordAttackCombo.h"

SwordAttackCombo::SwordAttackCombo(AActor *owner, UAnimInstance *animInstance,
                                   AAttackCollision *collision)
    : AttackAbility(owner, animInstance, collision) {
  // Set up the attack ability
  comboMontage_[0] = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack1.AM_Attack1"));
  comboDamage_[0] = {10.0, EDamageType::Physical, EDamageElementType::None};

  comboMontage_[1] = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack2.AM_Attack2"));
  comboDamage_[1] = {10.0, EDamageType::Physical, EDamageElementType::None};

  comboMontage_[2] = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack3.AM_Attack3"));
  comboDamage_[2] = {10.0, EDamageType::Physical, EDamageElementType::None};

  comboMontage_[3] = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack4.AM_Attack4"));
  comboDamage_[3] = {10.0, EDamageType::Physical, EDamageElementType::None};

  SetUpAttackAbility(comboMontage_[0], comboDamage_[0]);
  SetUpAttackAbility(comboMontage_[1], comboDamage_[1]);
  SetUpAttackAbility(comboMontage_[2], comboDamage_[2]);
  SetUpAttackAbility(comboMontage_[3], comboDamage_[3]);
}

void SwordAttackCombo::DoAbility() {
  // TODO:コンボがつながるかつながらないかの判定
  comboCount_ = (comboCount_ + 1) % 4;
  animMontage_ = comboMontage_[comboCount_];
  damage_ = comboDamage_[comboCount_];
  PlayMontage();
}
