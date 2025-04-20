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

USkillNotify *UAnimatedAttackSkillFactory::get_skill_notify(UAnimatedAttack *attack_module) {
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
