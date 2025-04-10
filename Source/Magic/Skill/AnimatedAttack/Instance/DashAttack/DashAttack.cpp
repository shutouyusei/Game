#include "DashAttack.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "../../AnimatedAttack.h"

void UDashAttack::Activate() {
  // 敵を貫通するようにコリジョンを設定
  if (skill_data_.level >= 2) {
    owner_->GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Overlap);
  }
  //  スキルの実行
  attack_module_->Attack();
}

void UDashAttack::OnMotageEnded(UAnimMontage *montage, bool interrupted) {
  // 敵を貫通しないようににコリジョンを設定
  if (skill_data_.level >= 2) {
    owner_->GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Block);
  }
}
