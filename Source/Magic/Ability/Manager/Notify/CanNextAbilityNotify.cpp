#include "CanNextAbilityNotify.h"
#include "GameFramework/Actor.h"
#include "Manager/AbilityManager.h"

void UCanNextAbilityNotify::Notify(USkeletalMeshComponent *MeshComp,
                                   UAnimSequenceBase *Animation) {
  // Check if the notify is called
  // Get the owner of the mesh
  AActor *owner = MeshComp->GetOwner();
  if (owner == nullptr) {
    return;
  }
  // Get Ability Manager
  UAbilityManager *manager = owner->FindComponentByClass<UAbilityManager>();
  if (manager == nullptr) {
    return;
  }
  // Set the ability manager to be able to input
  manager->SetAbilityFlag(EAbilityFlag::CanNextAbility);
  manager->ExecuteNext();
}
