#pragma once
#include "Ability.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

#include "AnimAbility.generated.h"

UCLASS()
class UAnimAbility : public UAbility {
  GENERATED_BODY()
protected:
  void PlayMontage();

private:
  UAnimInstance *GetAnimInstance();
  void OnMontageEnded(UAnimMontage *montage, bool interrupted);

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  TObjectPtr<UAnimMontage> anim_montage_;
};
