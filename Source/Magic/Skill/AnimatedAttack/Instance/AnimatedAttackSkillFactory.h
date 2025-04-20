#pragma once
#include "../../SkillFactory.h"
#include "../../Notify/SkillNotify.h"

#include "AnimatedAttackSkillFactory.generated.h"

class UAnimatedAttack;
struct FDamageInfo;

UCLASS()
class UAnimatedAttackSkillFactory : public USkillFactory {
  GENERATED_BODY()
protected:
  UAnimatedAttack *CreateAttackModule(USkillManager *manager, UAnimMontage *montage, FDamageInfo damage_info);
  FDamageInfo CreateDamageInfo(int32 level);
  USkillNotify *get_skill_notify(UAnimatedAttack *attack_module);
};
