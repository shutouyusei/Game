#pragma once
#include "Attack/AttackAbility.h"

class DodgeAttack1 : public AttackAbility {
public:
  DodgeAttack1(UAbilityManager *owner, UAnimInstance *animInstance,
               AAttackCollision *collision);
  ~DodgeAttack1() = default;
};
