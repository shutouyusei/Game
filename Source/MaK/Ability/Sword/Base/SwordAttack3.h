#pragma once
#include "Attack/AttackAbility.h"

class SwordAttack3 : public AttackAbility {
public:
  SwordAttack3(UAbilityManager *owner, UAnimInstance *animInstance,
               AAttackCollision *collision);
  ~SwordAttack3() = default;
};
