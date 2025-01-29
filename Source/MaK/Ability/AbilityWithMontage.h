#pragma once
#include "Ability.h"
#include "AbilityNotify.h"
#include "AbilityWithMontage.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CoreMinimal.h"

class UAnimInstance;
class UAnimMontage;

class AbilityWithMontage : public Ability {
public:
  AbilityWithMontage(AActor *owner, UAnimInstance *animInstance);

  virtual ~AbilityWithMontage();

  // NOTE:Don't call it from outside
  virtual void OnMontageEnded(UAnimMontage *montage, bool bInterrupted) {};

protected:
  void SetAnimNotifyDelegate(FName name, std::function<void()> beginDelegate,
                             std::function<void()> endDelegate);
  void PlayMontage();
  void StopMontage();
  void SetUpAbilityWithMontage();

protected:
  UPROPERTY()
  TArray<UAbilityNotify *> notifies_;
  UAnimInstance *animInstance_;
  UAnimMontage *animMontage_;
};
