#pragma once
#include "Ability.h"

class UAnimInstance;
class UAnimMontage;
class UAbilityNotify;

class AbilityWithMontage : public Ability {
public:
  AbilityWithMontage(UAbilityManager *owner, UAnimInstance *animInstance);
  virtual ~AbilityWithMontage();

protected:
  void SetAnimNotifyDelegate(FName name, std::function<void()> beginDelegate,
                             std::function<void()> endDelegate);
  void PlayMontage();
  void StopMontage();
  void SetUpAbilityWithMontage();

protected:
  TArray<UAbilityNotify *> notifies_;
  UAnimInstance *animInstance_;
  UAnimMontage *animMontage_;
};
