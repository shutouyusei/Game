#pragma once
#include "../AbilityFactory.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "AttackCollision.h"
#include "DamageStruct.h"
#include "GameFramework/Actor.h"

class AttackFactory : public AbilityFactory {
public:
  AttackFactory(UAnimMontage *animMontage, FDamageStruct damage, AActor *owner,
                AAttackCollision *weapon)
      : animMontage_(animMontage), damage_(damage), weapon_(weapon),
        owner_(owner) {};
  ~AttackFactory() = default;

  Ability *CreateAbility(UAnimInstance *animInstance) override;

private:
  UAnimMontage *animMontage_;
  FDamageStruct damage_;
  AAttackCollision *weapon_;
  AActor *owner_;
};
