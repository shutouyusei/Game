#include "AnimatedAttackSkillFactory.h"
#include "../../DamageInfo.h"
#include "../AnimatedAttackFactory.h"

UAnimatedAttack *UAnimatedAttackSkillFactory::CreateAttackModule(USkillManager *manager, UAnimMontage *montage, FDamageInfo damage_info) {
  UAnimatedAttackFactory *factory = NewObject<UAnimatedAttackFactory>();
  UAnimatedAttack *attack_module = factory->Create(manager, montage, damage_info);
  factory = nullptr;
  return attack_module;
}

FDamageInfo UAnimatedAttackSkillFactory::CreateDamageInfo(int32 level) {
  FSkillData skill_data = get_skill_data(level);
  FDamageInfo damage_info = {skill_data.potency};
  return damage_info;
}
