#pragma once
#include "../../../SkillFactory.h"

#include "DashAttackFactory.generated.h"

struct FDamageInfo;
class UAnimatedAttack;

UCLASS()
class UDashAttackFactory : public USkillFactory {
  GENERATED_BODY()

private:
  UAnimatedAttack *CreateAttackModule(USkillManager *manager, UAnimMontage *montage, FDamageInfo damage_info);
  USkill *CreateSkill(int32 level, USkillManager *manager) override;
  void DisableInvincibleNotify(TArray<FAnimNotifyEvent> Notifies);
  FDamageInfo CreateDamageInfo(int32 level);

private:
  UPROPERTY(EditAnywhere)
  UAnimMontage *montage_;
};
