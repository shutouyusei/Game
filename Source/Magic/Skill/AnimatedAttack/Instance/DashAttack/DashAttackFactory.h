#pragma once
#include "../AnimatedAttackSkillFactory.h"

#include "DashAttackFactory.generated.h"

struct FDamageInfo;
class UAnimatedAttack;

UCLASS()
class UDashAttackFactory : public UAnimatedAttackSkillFactory {
  GENERATED_BODY()
private:
  USkill *CreateSkill(int32 level, USkillManager *manager) override;

private:
  UPROPERTY(EditAnywhere)
  UAnimMontage *montage_;
};
