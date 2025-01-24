#pragma once
#include "../AbilityWithMontage.h"
#include "AttackCollision.h"
#include "DamageStruct.h"

class AttackAbility : public AbilityWithMontage {
public:
  AttackAbility(AActor *owner, UAnimInstance *animInstance,
                AAttackCollision *collisionm);
  ~AttackAbility() = default;
  virtual void DoAbility() override;
  virtual void EndAbility() override;

protected:
  void SetUpAttackAbility(UAnimMontage *animMontage, FDamageStruct damage);
  FDamageStruct damage_;
  AAttackCollision *collision_;
};
