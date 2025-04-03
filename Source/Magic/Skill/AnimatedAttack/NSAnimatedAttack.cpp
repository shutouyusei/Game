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
      hit_result, start, end, FQuat::Identity, ECollisionChannel::ECC_Visibility,
      FCollisionShape::MakeSphere(radius_), FCollisionQueryParams(FName(), false));
  if (bHit) {
    ACharacter *target = Cast<ACharacter>(hit_result.GetActor());
    if (target) {
      if (!targets_.Contains(target)) {
        targets_.Add(target);
        OnAttack(target);
      }
    }
  }
}

void UNSAnimatedAttack::OnAttack(ACharacter *target) {
  // TODO:ライントレースが正常にコールバックを呼び出せているか
  if (attack_module_) {
    attack_module_->OnAttack(target);
  }
}
