#include "AnimAbility.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CanInputNotify.h"
#include "CanNextAbilityNotify.h"
#include "CoreMinimal.h"
#include "Gameframework/Character.h"

void UAnimAbility::PlayMontage() {
  // Get AnimInstance
  UAnimInstance *anim_instance = GetAnimInstance();
  // モンタージュを再生
  anim_instance->Montage_Play(anim_montage_);
  // モンタージュ再生後でしかdelegateの設定ができない！！
  FOnMontageEnded del;
  del.BindUObject(this, &UAnimAbility::OnMontageEnded);
  anim_instance->Montage_SetEndDelegate(del, anim_montage_);
}

void UAnimAbility::OnMontageEnded(UAnimMontage *montage, bool interrupted) {
  if (!interrupted) {
    EndAbility();
  }
}

UAnimInstance *UAnimAbility::GetAnimInstance() {
  ACharacter *character = Cast<ACharacter>(manager_->GetOwner());
  return character->GetMesh()->GetAnimInstance();
}
