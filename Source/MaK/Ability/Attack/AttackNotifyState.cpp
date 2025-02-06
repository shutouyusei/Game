#include "AttackNotifyState.h"
#include "../AbilityManager.h"
#include "AttackCollision.h"

void UAttackNotifyState::NotifyBegin(USkeletalMeshComponent *MeshComp,
                                     UAnimSequenceBase *Animation,
                                     float TotalDuration) {
  // Get the owner of the mesh
  AActor *owner = MeshComp->GetOwner();
  if (owner == nullptr)
    return;
  // Get Ability Manager
  UAbilityManager *abilityManager =
      owner->FindComponentByClass<UAbilityManager>();
  if (abilityManager == nullptr)
    return;
  // set attack collision to be able to deal damage
  abilityManager->attackCollision_->SetActorEnableCollision(true);
}


void UAttackNotifyState::NotifyEnd(USkeletalMeshComponent *MeshComp,
                                   UAnimSequenceBase *Animation) {
  // Get the owner of the mesh
  AActor *owner = MeshComp->GetOwner();
  if (owner == nullptr)
    return;
  // Get Ability Manager
  UAbilityManager *abilityManager =
      owner->FindComponentByClass<UAbilityManager>();
  if (abilityManager == nullptr)
    return;
  // set attack collision to be unable to deal damage
  abilityManager->attackCollision_->SetActorEnableCollision(false);
}\
