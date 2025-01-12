#pragma once
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CoreMinimal.h"

class Ability {
public:
  Ability(UAnimInstance *animInstance, UAnimMontage *animMontage)
      : animInstance_(animInstance), animMontage_(animMontage) {};
  virtual ~Ability() = default;
  virtual void DoAbility(FTransform transform) = 0;

protected:
  UAnimInstance *animInstance_;
  UAnimMontage *animMontage_;
};

class AbilityFactory {
  //NOTE:BeginPlayにてanimInstanceは生成される
  //それ以前でAbilityをCreateするとanimInstance がnullptrになる
public:
  virtual ~AbilityFactory() = default;
  virtual Ability *CreateAbility(UAnimInstance *animInstance) = 0;
};
