#pragma once
#include "Attack/AttackAbility.h"

class SwordAttackCombo : public AttackAbility {
public:
  SwordAttackCombo(AActor *owner, UAnimInstance *animInstance,
                   AAttackCollision *collision);
  ~SwordAttackCombo() = default;

  virtual void DoAbility() override;
  virtual void EndAbility() override;

private:
  UAnimMontage *comboMontage_[4];
  FDamageStruct comboDamage_[4];

  int comboCount_ = 0;
};
