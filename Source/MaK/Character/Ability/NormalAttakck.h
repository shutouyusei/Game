#pragma once
#include "Attack/AttackAbility.h"

class NormalAttackFactory : public AbilityFactory {
public:
  Ability *CreateAbility(UAnimInstance *animInstance) override;
};
