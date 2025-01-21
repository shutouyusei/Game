#pragma once
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CoreMinimal.h"

class Ability {
public:
  Ability(UAnimInstance *animInstance, UAnimMontage *animMontage);
  virtual ~Ability() = default;
  virtual void DoAbility(FTransform transform) = 0;
  virtual void OnMontageEnded(UAnimMontage *montage, bool bInterrupted);

protected:
  void PlayMontage();

private:
  UAnimInstance *animInstance_;
  UAnimMontage *animMontage_;
};

// NOTE:BeginPlayにてanimInstanceは生成される
// それ以前でAbilityをCreateするとanimInstance がnullptrになる
class AbilityFactory {
public:
  virtual ~AbilityFactory() = default;
  virtual Ability *CreateAbility(UAnimInstance *animInstance) = 0;
};
