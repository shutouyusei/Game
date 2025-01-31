#pragma once
#include "../AbilityWithMontage.h"
#include "Damage.h"

class AAttackCollision;
struct FDamageStruct;

class AttackAbility : public AbilityWithMontage {
public:
  AttackAbility(UAbilityManager *owner, UAnimInstance *animInstance,
                AAttackCollision *collisionm);
  ~AttackAbility() = default;
  virtual void DoAbility() override;
  virtual void EndAbility() override;

protected:
  void SetUpAttackAbility(UAnimMontage *animMontage, FDamageStruct damage);
  FDamageStruct damage_;
  AAttackCollision *collision_;
};
