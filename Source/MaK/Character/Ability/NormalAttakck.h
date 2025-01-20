#pragma once
#include "Attack/AttackAbility.h"
#include "Attack/AttackCollision.h"

class StatsBase;
class NormalAttackFactory : public AbilityFactory {
public:
  NormalAttackFactory(AAttackCollision *weapon, StatsBase *stats)
      : weapon_(weapon), stats_(stats) {}
  Ability *CreateAbility(UAnimInstance *animInstance) override;

private:
  AAttackCollision *weapon_;
  StatsBase *stats_;
};
