#pragma once
#include "AbilityNotify.h"
#include "CoreMinimal.h"

class UAbilityNotify;
class UAnimInstance;
class UAnimMontage;

class Ability {
public:
  Ability(UAnimInstance *animInstance, UAnimMontage *animMontage);
  virtual ~Ability();
  virtual void DoAbility() = 0;

  virtual void OnMontageEnded(UAnimMontage *montage, bool bInterrupted);
  void SetAnimNotifyDelegate(FName name, std::function<void()> beginDelegate,
                             std::function<void()> endDelegate);
  UAnimMontage *GetAnimMontage() { return animMontage_; }
  UAnimInstance *GetAnimInstance() { return animInstance_; }

protected:
  void PlayMontage();

  UPROPERTY()
  TArray<UAbilityNotify *> notifies_;

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
