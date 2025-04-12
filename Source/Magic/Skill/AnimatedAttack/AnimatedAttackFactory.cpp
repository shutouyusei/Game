#include "AnimatedAttackFactory.h"
#include "../SkillManager/SkillManager.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"
#include "NSAnimatedAttack.h"

UAnimatedAttack *UAnimatedAttackFactory::Create(USkillManager *manager, UAnimMontage *montage, FDamageInfo damage_info) {
  // create animation
  ACharacter *character = Cast<ACharacter>(manager->GetOwner());
  USkeletalMeshComponent *mesh = character->GetMesh();
  UAnimInstance *anim_instance = mesh->GetAnimInstance();
  // copy montage
  UAnimMontage *d_montage = DuplicateObject<UAnimMontage>(montage, manager);
  // create attack module
  UAnimatedAttack *attack_module = NewObject<UAnimatedAttack>(manager);
  // construct
  attack_module->montage_ = d_montage;
  attack_module->anim_instance_ = anim_instance;
  attack_module->damage_info_ = damage_info;
  // Notify State
  AActor *owner = Cast<AActor>(character);
  SetNSAnimatedAttack(attack_module, owner);
  return attack_module;
}

void UAnimatedAttackFactory::SetNSAnimatedAttack(UAnimatedAttack *attack_module, AActor *character) {
  for (const FAnimNotifyEvent &notify_event : attack_module->montage_->Notifies) {
    if (notify_event.NotifyStateClass) {
      UNSAnimatedAttack *attack_notify = Cast<UNSAnimatedAttack>(notify_event.NotifyStateClass);
      if (attack_notify) {
        attack_notify->attack_module_ = attack_module;
        attack_notify->owner_ = character;
      }
    }
  }
}
