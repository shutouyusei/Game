#include "DashAttack.h"
#include "../../AnimatedAttack.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"

void UDashAttack::Activate() {
  // 敵を貫通するようにコリジョンを設定
  if (level_ >= 2) {
    owner_->GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Overlap);
  }
  //  スキルの実行
  attack_module_->Attack();
}

void UDashAttack::OnMotageEnded(UAnimMontage *montage, bool interrupted) {
  // 敵を貫通しないようににコリジョンを設定
  if (level_ >= 2) {
    owner_->GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Block);
  }
}

void UDashAttack::Invincible() {
}
