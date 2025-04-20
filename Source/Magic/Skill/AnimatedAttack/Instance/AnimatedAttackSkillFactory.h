#pragma once
#include "../../SkillFactory.h"

#include "AnimatedAttackSkillFactory.generated.h"

class UAnimatedAttack;
struct FDamageInfo;

UCLASS()
class UAnimatedAttackSkillFactory : public USkillFactory {
  GENERATED_BODY()
protected:
  UAnimatedAttack *CreateAttackModule(USkillManager *manager, UAnimMontage *montage, FDamageInfo damage_info);
  FDamageInfo CreateDamageInfo(int32 level);
};
