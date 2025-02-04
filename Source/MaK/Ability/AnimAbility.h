#pragma once
#include "Ability.h"

#include "UAnimAbility.generated.h"

class UAnimInstance;
class UAnimMontage;
class UAbilityNotify;

UCLASS()
class UAnimAbility : public UAbility {
public:
  UAnimAbility();
  virtual ~UAnimAbility();

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
