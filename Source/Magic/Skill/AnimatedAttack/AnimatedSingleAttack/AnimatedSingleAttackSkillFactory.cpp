#include "AnimatedSingleAttackSkillFactory.h"
#include "../AnimatedAttack.h"
#include "../NSAnimatedAttack.h"
#include "AnimatedSingleAttackSkill.h"
#include "GameFramework/Character.h"

USkill *UAnimatedSingleAttackSkillFactory::Create(USkillManager *manager) {
  // skill
  UAnimatedSingleAttackSkill *skill = NewObject<UAnimatedSingleAttackSkill>(manager, skill_class_);
  skill->manager_ = manager;
  // Create
  UAnimatedAttack *attack_module = CreateAnimatedAttack(manager);
  skill->attack_module_ = attack_module;
  SetNSAnimatedAttack(attack_module);
  return skill;
}

UAnimatedAttack *UAnimatedSingleAttackSkillFactory::CreateAnimatedAttack(USkillManager *manager) {
  // create anim
  ACharacter *character = Cast<ACharacter>(manager->GetOwner());
  USkeletalMeshComponent *mesh = character->GetMesh();
  UAnimInstance *anim_instance = mesh->GetAnimInstance();
  UAnimMontage *montage = NewObject<UAnimMontage>(manager, montage_class_);
  // create attack module
  UAnimatedAttack *attack_module = NewObject<UAnimatedAttack>(manager);
  // set
  attack_module->montage_ = montage;
  attack_module->anim_instance_ = anim_instance;
  return attack_module;
}

void UAnimatedSingleAttackSkillFactory::SetNSAnimatedAttack(UAnimatedAttack *attack_module) {
  for (const FAnimNotifyEvent &notify_event : attack_module->montage_->Notifies) {
    if (notify_event.NotifyStateClass) {
      UNSAnimatedAttack *attack_notify = Cast<UNSAnimatedAttack>(notify_event.NotifyStateClass);
      if (attack_notify) {
        attack_notify->attack_module_ = attack_module;
        break;
      }
    }
  }
}
