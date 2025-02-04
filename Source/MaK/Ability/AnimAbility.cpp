#include "AnimAbility.h"
#include "Ability.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CanInputNotify.h"
#include "CanNextAbilityNotify.h"
#include "CoreMinimal.h"
#include "Gameframework/Character.h"

UAnimAbility::UAnimAbility() : UAbility() {}

UAnimAbility::~UAnimAbility() {}

void UAnimAbility::PlayMontage() {
  // Get AnimInstance
  UAnimInstance *animInstance = GetAnimInstance();
  //モンタージュを再生
  animInstance->Montage_Play(animMontage_);
  // NOTE:モンタージュ再生後でしかdelegateの設定ができない！！
  FOnMontageEnded del;
  del.BindUObject(this, &UAnimAbility::OnMontageEnded);
  animInstance->Montage_SetEndDelegate(del, animMontage_);
}

// NOTE:ここの関数いるかわからん
void UAnimAbility::StopMontage() {
  // Get AnimInstance
  UAnimInstance *animInstance = GetAnimInstance();
  // NOTE: 0.0fで即座に停止
  animInstance->Montage_Stop(0.0f, animMontage_);
  EndAbility();
}

void UAnimAbility::OnMontageEnded(UAnimMontage *montage, bool interrupted) {
  EndAbility();
}

UAnimInstance *UAnimAbility::GetAnimInstance() {
  ACharacter *character = Cast<ACharacter>(owner_->GetOwner());
  return character->GetMesh()->GetAnimInstance();
}
