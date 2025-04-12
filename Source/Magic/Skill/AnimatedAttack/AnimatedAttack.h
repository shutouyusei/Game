#pragma once
#include "../DamageInfo.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "AnimatedAttack.generated.h"

class ACharacter;
class USkeletalMeshComponent;
class UAnimMontage;
class UAnimInstance;

DECLARE_DELEGATE_OneParam(FOnAttack, ACharacter *);
DECLARE_DELEGATE_TwoParams(FOnAttackEnd, UAnimMontage *, bool);

UCLASS(Blueprintable)
class UAnimatedAttack : public UObject {
  GENERATED_BODY()
public:
  void Attack();
  void OnAttack(ACharacter *target);

private:
  void OnAttackEnd(UAnimMontage *montage, bool interrupted);

public:
  UPROPERTY()
  TObjectPtr<UAnimMontage> montage_;
  UPROPERTY()
  TObjectPtr<UAnimInstance> anim_instance_;
  UPROPERTY()
  FDamageInfo damage_info_;
  FOnAttack on_attack_;
  FOnAttackEnd on_attack_end_;
};
