#include "DashAttackFactory.h"
#include "../../../Notify/Status/NSInvincible.h"
#include "../../AnimatedAttackFactory.h"
#include "DashAttack.h"
#include "GameFramework/Character.h"

USkill *UDashAttackFactory::Create(USkillManager *manager) {
  // Create module
  TObjectPtr<UAnimatedAttackFactory> factory = NewObject<UAnimatedAttackFactory>(this);
  UAnimatedAttack *attack_module = factory->Create(manager, montage_);
  // skill create
  UDashAttack *skill = NewObject<UDashAttack>(manager);
  // set data
  skill->manager_ = manager;
  skill->attack_module_ = attack_module;
  skill->skill_data_ = data_;
  skill->owner_ = Cast<ACharacter>(manager->GetOwner());
  // set function
  attack_module->on_attack_end_.BindUObject(skill, &UDashAttack::OnMotageEnded);
  if (data_.level < 3) {
    DisableInvincibleNotify(attack_module->montage_->Notifies);
  }
  return skill;
}

void UDashAttackFactory::DisableInvincibleNotify(TArray<FAnimNotifyEvent> Notifies) {
  if (data_.level >= 2) {
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
}
