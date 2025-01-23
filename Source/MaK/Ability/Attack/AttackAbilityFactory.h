#pragma once
#include "AttackAbility.h"
#include "AttackCollision.h"

class StatsBase;
struct FDamageStruct;

class AttackFactory : public AbilityFactory {
public:
  AttackFactory(UAnimMontage *animMontage, FDamageStruct damage,
                AAttackCollision *weapon, StatsBase *stats)
      : animMontage_(animMontage), damage_(damage), weapon_(weapon),
        stats_(stats) {};

  Ability *CreateAbility(UAnimInstance *animInstance) override;

private:
  UAnimMontage *animMontage_;
  FDamageStruct damage_;
  AAttackCollision *weapon_;
  StatsBase *stats_;
};
