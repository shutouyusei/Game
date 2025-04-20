#pragma once
#include "../../../SkillFactory.h"

#include "NormalSwordAttackFactory.generated.h"

class UAnimatedAttack;
struct FDamageInfo;
class USkillNotify;

UCLASS()
class UNormalSwordAttackFactory : public USkillFactory {
  GENERATED_BODY()
private:
  USkill *CreateSkill(int32 level, USkillManager *manager) override;
  UAnimatedAttack *CreateAttackModule(USkillManager *manager, UAnimMontage *montage, FDamageInfo damage_info);
  USkillNotify *get_skill_notify(UAnimatedAttack *attack_module);
  FDamageInfo CreateDamageInfo(int32 level);

private:
  UPROPERTY(EditAnywhere)
  TArray<UAnimMontage *> montages_on_ground_;
  UPROPERTY(EditAnywhere)
  TArray<UAnimMontage *> montages_in_air_;
};
