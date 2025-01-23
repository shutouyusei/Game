#pragma once
#include "AbilityNotify.h"
#include "CoreMinimal.h"

class UAbilityNotify;
class UAnimInstance;
class UAnimMontage;
class AActor;

class Ability {
public:
  Ability(UAnimInstance *animInstance, UAnimMontage *animMontage,
          AActor *owner);

  virtual ~Ability();

  virtual void DoAbility();

  void SetAnimNotifyDelegate(FName name, std::function<void()> beginDelegate,
                             std::function<void()> endDelegate);

  // NOTE:Don't call it from outside
  virtual void OnMontageEnded(UAnimMontage *montage, bool bInterrupted);

protected:
  void PlayMontage();

protected:
  UPROPERTY()
  TArray<UAbilityNotify *> notifies_;

  AActor *owner_;

private:
  UAnimInstance *animInstance_;
  UAnimMontage *animMontage_;
};
