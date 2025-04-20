#include "DashAttackFactory.h"
#include "../../../DamageInfo.h"
#include "../../../Notify/Status/NSInvincible.h"
#include "../../AnimatedAttackFactory.h"
#include "DashAttack.h"
#include "GameFramework/Character.h"

USkill *UDashAttackFactory::CreateSkill(int32 level, USkillManager *manager) {
  // skill create
  UDashAttack *skill = NewObject<UDashAttack>(manager);
  // set data
  skill->attack_module_ = CreateAttackModule(manager, montage_, CreateDamageInfo(level));
  skill->owner_ = Cast<ACharacter>(manager->GetOwner());
  // set function
  skill->attack_module_->on_attack_end_.BindUObject(skill, &UDashAttack::OnMotageEnded);
  if (level < 3) {
    DisableInvincibleNotify(skill->attack_module_->montage_->Notifies);
  }
  return skill;
}

UAnimatedAttack *UDashAttackFactory::CreateAttackModule(USkillManager *manager, UAnimMontage *montage, FDamageInfo damage_info) {
  TObjectPtr<UAnimatedAttackFactory> factory = NewObject<UAnimatedAttackFactory>();
  UAnimatedAttack *attack_module = factory->Create(manager, montage, damage_info);
  factory = nullptr;
  return attack_module;
}

void UDashAttackFactory::DisableInvincibleNotify(TArray<FAnimNotifyEvent> Notifies) {
  for (const FAnimNotifyEvent &notify_event : Notifies) {
    if (notify_event.NotifyStateClass) {
      UNSInvincible *invincible_notify = Cast<UNSInvincible>(notify_event.NotifyStateClass);
      if (invincible_notify) {
        invincible_notify->bCanActive = true;
      }
      break;
    }
  }
}

FDamageInfo UDashAttackFactory::CreateDamageInfo(int32 level){
  FSkillData skill_data = get_skill_data(level);
  FDamageInfo damage_info = {skill_data.potency};
  return damage_info;
}
