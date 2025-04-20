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
  void DisableInvincibleNotify(TArray<FAnimNotifyEvent> Notifies);

private:
  UPROPERTY(EditAnywhere)
  UAnimMontage *montage_;
};
