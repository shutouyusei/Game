#pragma once
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "AnimatedAttack.generated.h"

class ACharacter;
class USkeletalMeshComponent;

DECLARE_DELEGATE_OneParam(FOnAttack, ACharacter *);

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
  FOnAttack on_attack_;
};
