#include "NormalSwordAttackFactory.h"
#include "../../../DamageInfo.h"
#include "../../../Notify/SkillNotify.h"
#include "../../AnimatedAttackFactory.h"
#include "GameFramework/Character.h"
#include "NormalSwordAttack.h"

USkill *UNormalSwordAttackFactory::CreateSkill(int32 level, USkillManager *manager) {
  // Create skill
  UNormalSwordAttack *skill = NewObject<UNormalSwordAttack>(manager);
  // create attack modules
  for (int in_air = 0; in_air < 2; in_air++) {
    TArray<UAnimMontage *> montages = in_air == 0 ? montages_on_ground_ : montages_in_air_;
    for (int32 j = 0; j <= level; j++) {
      UAnimatedAttack *attack_module = CreateAttackModule(manager, montages[j], CreateDamageInfo(j));
      USkillNotify *skill_notify = get_skill_notify(attack_module);
      skill_notify->skill_effect_.BindUObject(skill, &UNormalSwordAttack::EndCombo);
      if (in_air == 0) {
        skill->attack_on_ground_modules_.Add(attack_module);
      } else {
        skill->attack_in_air_modules_.Add(attack_module);
      }
    }
  }
  return skill;
}

UAnimatedAttack *UNormalSwordAttackFactory::CreateAttackModule(USkillManager *manager, UAnimMontage *montage, FDamageInfo damage_info) {
  // create attack modules
  UAnimatedAttackFactory *attack_factory = NewObject<UAnimatedAttackFactory>();
  // create attack_module
  UAnimatedAttack *attack_module = attack_factory->Create(manager, montage, damage_info);
  attack_factory = nullptr;
  return attack_module;
}

USkillNotify *UNormalSwordAttackFactory::get_skill_notify(UAnimatedAttack *attack_module) {
  for (const FAnimNotifyEvent &notify_event : attack_module->montage_->Notifies) {
    if (notify_event.Notify) {
      USkillNotify *skill_notify = Cast<USkillNotify>(notify_event.Notify);
      if (skill_notify) {
        return skill_notify;
      }
    }
  }
  return nullptr;
}

FDamageInfo UNormalSwordAttackFactory::CreateDamageInfo(int32 level) {
  // create damage information
  FSkillData skill_data = get_skill_data(level);
  FDamageInfo damage_info = {skill_data.potency * (1.0f + level * 0.1f)}; // return damage information
  return damage_info;
}
