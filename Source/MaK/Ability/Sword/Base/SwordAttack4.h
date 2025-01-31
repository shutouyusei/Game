#pragma once
#include "Attack/AttackAbility.h"

class SwordAttack4 : public AttackAbility {
public:
  SwordAttack4(UAbilityManager *owner, UAnimInstance *animInstance,
               AAttackCollision *collision);
  ~SwordAttack4() = default;
};
