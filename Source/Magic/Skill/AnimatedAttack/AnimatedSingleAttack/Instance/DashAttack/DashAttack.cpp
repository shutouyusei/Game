#include "DashAttack.h"
#include "../../../../Notify/Status/NSInvincible.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"

void UDashAttack::SetSkillData(FSkillData data) {
  // スキルデータの設定
  UAnimatedSingleAttackSkill::SetSkillData(data);
  attack_module_->on_attack_end_.BindUObject(this, &UDashAttack::OnMotageEnded);
  if (data.level < 3) {
    for (const FAnimNotifyEvent &notify_event : attack_module_->montage_->Notifies) {
      if (notify_event.NotifyStateClass) {
        UNSInvincible *invincible_notify = Cast<UNSInvincible>(notify_event.NotifyStateClass);
        invincible_notify->bCanActive = false;
        break;
      }
    }
  }
  owner_ = Cast<ACharacter>(manager_->GetOwner());
}

void UDashAttack::Activate() {
  // 敵を貫通するようにコリジョンを設定
  // TODO:コリジョンの設定
  owner_->GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Overlap);
  //  スキルの実行
  attack_module_->Attack();
}

void UDashAttack::OnMotageEnded(UAnimMontage *montage, bool interrupted) {
  // 敵を貫通しないようににコリジョンを設定
  owner_->GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Block);
}
