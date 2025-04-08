#include "NSInvincible.h"

void UNSInvincible::NotifyBegin(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, float TotalDuration) {
  if (!bCanActive) {
    return;
  }
  UE_LOG(LogTemp, Warning, TEXT("Invincible Notify Begin"));
}

void UNSInvincible::NotifyEnd(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation) {
  if (!bCanActive) {
    return;
  }
}
