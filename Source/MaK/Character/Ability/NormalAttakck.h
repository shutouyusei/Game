#pragma once
#include "Attack/AttackAbility.h"
#include "Attack/AttackCollision.h"

class NormalAttackFactory : public AbilityFactory {
public:
  NormalAttackFactory(AAttackCollision *weapon) : weapon_(weapon) {}
  Ability *CreateAbility(UAnimInstance *animInstance) override;

private:
  AAttackCollision *weapon_;
};
