#pragma once
#include "../Ability.h"

class UShapeComponent;

class AttackAbility : public Ability {
public:
  AttackAbility(UAnimInstance *animInstance, UAnimMontage *animMontage,
                UShapeComponent *collision);
  void DoAbility(FTransform transform) override;

private:
  UShapeComponent *collision_;
};
