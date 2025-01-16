#pragma once
#include "Attack/AttackAbility.h"

class UShapeComponent;

class NormalAttackFactory : public AbilityFactory {
public:
  NormalAttackFactory(UShapeComponent *weapon) : weapon_(weapon) {}
  Ability *CreateAbility(UAnimInstance *animInstance) override;
private:
  UShapeComponent *weapon_;
};
