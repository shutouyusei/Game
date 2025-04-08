#include "NSAnimatedAttack.h"
#include "AnimatedAttack.h"
#include "CollisionQueryParams.h" // FCollisionQueryParams のため
#include "DrawDebugHelpers.h"     // デバッグ用
#include "Engine/World.h"         // GetWorld() のため
#include "GameFramework/Character.h"

void UNSAnimatedAttack::NotifyBegin(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, float TotalDuration) {
  targets_.Empty();
}
void UNSAnimatedAttack::NotifyTick(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, float FrameDeltaTime) {
  PerformTrace(MeshComp);
}

void UNSAnimatedAttack::PerformTrace(USkeletalMeshComponent *mesh) {
  FVector start = mesh->GetSocketLocation(socket_name_);
  FVector end = start + (mesh->GetSocketRotation(socket_name_).Vector() * reach_);

  FHitResult hit_result;

  bool bHit = GetWorld()->SweepSingleByChannel(
      hit_result, start, end, FQuat::Identity, ECollisionChannel::ECC_Pawn,
      FCollisionShape::MakeSphere(radius_), FCollisionQueryParams(FName(), false, owner_));

  FColor DrawColor = bHit ? FColor::Red : FColor::Green;
  DrawDebugSphere(GetWorld(), start, radius_, 12, DrawColor, false, 0.5f);
  DrawDebugSphere(GetWorld(), end, radius_, 12, DrawColor, false, 0.5f);
  if (bHit) {
    ACharacter *target = Cast<ACharacter>(hit_result.GetActor());
    if (target) {
      if (target == owner_) {
        return;
      }
      if (!targets_.Contains(target)) {
        targets_.Add(target);
        OnAttack(target);
      }
    }
  }
}

void UNSAnimatedAttack::OnAttack(ACharacter *target) {
  // TODO:複数人が呼び出しても独立しているか確認
  if (attack_module_) {
    UE_LOG(LogTemp, Warning, TEXT("Attack %s"), *target->GetName());
    attack_module_->OnAttack(target);
  }
}
