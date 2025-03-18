#include "AttackNotifyState.h"
#include "Manager/AbilityManager.h"

void UAttackNotifyState::NotifyBegin(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, float TotalDuration) {
  // Get the owner of the mesh
  AActor *owner = MeshComp->GetOwner();
  if (owner == nullptr)
    return;
  // Get Ability Manager
  UAbilityManager *manager = owner->FindComponentByClass<UAbilityManager>();
  if (manager == nullptr)
    return;
  // set attack collision to be able to deal damage
  manager->attack_collision_->SetActorEnableCollision(true);
}

void UAttackNotifyState::NotifyEnd(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation) {
  // Get the owner of the mesh
  AActor *owner = MeshComp->GetOwner();
  if (owner == nullptr)
    return;
  // Get Ability Manager
  UAbilityManager *manager = owner->FindComponentByClass<UAbilityManager>();
  if (manager == nullptr)
    return;
  // set attack collision to be unable to deal damage
  manager->attack_collision_->SetActorEnableCollision(false);
}
