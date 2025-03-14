#pragma once
#include "Ability.h"

#include "AnimAbility.generated.h"

class UAnimInstance;
class UAnimMontage;
// NOTE: アビリティとモンタージュは1:1の関係になる

UCLASS()
class UAnimAbility : public UAbility {
  GENERATED_BODY()
public:
  UAnimAbility() = default;
  virtual ~UAnimAbility() = default;

protected:
  void PlayMontage();

private:
  UAnimInstance *GetAnimInstance();
  void OnMontageEnded(UAnimMontage *montage, bool interrupted);

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  UAnimMontage *anim_montage_;
};
