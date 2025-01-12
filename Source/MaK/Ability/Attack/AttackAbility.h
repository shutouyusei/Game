#pragma once
#include "../Ability.h"

class AActor;

class AttackAbility : public Ability {
public:
  AttackAbility(UAnimInstance *animInstance, UAnimMontage *animMontage,
                AActor *collision);
  void DoAbility(FTransform transform) override;

private:
//TODO:BOXCOLLISIONで良きかも
  AActor *collision_;
};
