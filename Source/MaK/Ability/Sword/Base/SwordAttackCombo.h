#pragma once
#include "Ability.h"

class AAttackCollision;
class UAnimInstance;

class SwordAttackCombo : public Ability {
public:
  SwordAttackCombo(UAbilityManager *owner, UAnimInstance *animInstance,
                   AAttackCollision *collision);
  ~SwordAttackCombo();

  virtual void DoAbility() override;
  virtual void EndAbility() override;
  virtual bool IsExecuting() override {
    return comboAbilities_[comboCount_]->IsExecuting();
  }

private:
  Ability *comboAbilities_[4];
  int comboCount_ = 0;
};
