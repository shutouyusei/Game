#pragma once
#include "Attack/AttackAbility.h"

class SwordAttack1 : public AttackAbility {
public:
  SwordAttack1(AActor *owner, UAnimInstance *animInstance,
               AAttackCollision *collision);
  ~SwordAttack1() = default;
};
