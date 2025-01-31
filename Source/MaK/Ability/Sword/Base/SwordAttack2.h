#pragma once
#include "Attack/AttackAbility.h"

class SwordAttack2 : public AttackAbility {
public:
  SwordAttack2(UAbilityManager *owner, UAnimInstance *animInstance,
               AAttackCollision *collision);
  ~SwordAttack2() = default;
};
