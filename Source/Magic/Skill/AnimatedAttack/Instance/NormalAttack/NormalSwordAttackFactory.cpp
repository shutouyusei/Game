#include "NormalSwordAttackFactory.h"
#include "../../../DamageInfo.h"
#include "../../AnimatedAttackFactory.h"
#include "GameFramework/Character.h"
#include "NormalSwordAttack.h"

USkill *UNormalSwordAttackFactory::Create(int32 level, USkillManager *manager) {
  FSkillData skill_data = get_skill_data(level);
  // Create skill
  UNormalSwordAttack *skill = NewObject<UNormalSwordAttack>(manager);
  // create attack modules
  UAnimatedAttackFactory *attack_factory = NewObject<UAnimatedAttackFactory>();
  for (int32 i = 0; i <= level; i++) {
    UAnimatedAttack *attack_module = CreateAttackModules(i, manager, attack_factory, montages_on_ground_[i]);
    skill->attack_on_ground_modules_.Add(attack_module);
  }
  for (int32 i = 0; i <= level; i++) {
    UAnimatedAttack *attack_module = CreateAttackModules(i, manager, attack_factory, montages_in_air_[i]);
    skill->attack_in_air_modules_.Add(attack_module);
  }
  attack_factory = nullptr;
  // set variables to skill
  skill->manager_ = manager;
  skill->level_ = level;
  skill->skill_data_ = skill_data;
  return skill;
}

UAnimatedAttack *UNormalSwordAttackFactory::CreateAttackModules(int32 level, USkillManager *manager, UAnimatedAttackFactory *attack_factory, UAnimMontage *montage) {
  // create damage information
  FSkillData skill_data = get_skill_data(level);
  FDamageInfo damage_info = {skill_data.potency * (1.0f + level * 0.1f)};
  // create attack module
  return attack_factory->Create(manager, montage, damage_info);
}
