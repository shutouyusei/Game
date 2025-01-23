#pragma once
#include "Ability.h"
#include "Animation/AnimInstance.h"

// NOTE:BeginPlayにてanimInstanceは生成される
// それ以前でAbilityをCreateするとanimInstance がnullptrになる
class AbilityFactory {
public:
  AbilityFactory();
  virtual ~AbilityFactory() = default;
  virtual Ability *CreateAbility(UAnimInstance *animInstance) = 0;
};
