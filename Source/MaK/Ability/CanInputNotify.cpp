#include "CanInputNotify.h"
#include "AbilityManager.h"
#include "GameFramework/Actor.h"

void UCanInputNotify::Notify(USkeletalMeshComponent *MeshComp,
                             UAnimSequenceBase *Animation) {
  // Check if the notify is called
  // Get the owner of the mesh
  AActor *owner = MeshComp->GetOwner();
  if (owner == nullptr) {
    return;
  }
  // Get Ability Manager
  UAbilityManager *abilityManager =
      owner->FindComponentByClass<UAbilityManager>();
  if (abilityManager == nullptr) {
    return;
  }
  // Set the ability manager to be able to input
  abilityManager->CanInput();
}
