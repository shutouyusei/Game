#include "MultiAnimAbility.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CoreMinimal.h"
#include "Gameframework/Character.h"
// Ability Manager
#include "AbilityManager.h"
// Notify
#include "CanInputNotify.h"
#include "CanNextAbilityNotify.h"

UMultiAnimAbility::UMultiAnimAbility() : UAbility() {}

UMultiAnimAbility::~UMultiAnimAbility() {}
// TODO:攻撃アビリティに適応しないといけない

void UMultiAnimAbility::Tick(float DeltaTime, ELevelTick TickType,
                             FActorComponentTickFunction *ThisTickFunction) {
  // Endする条件を記述
  if (PlayEndAbility() && !isEnd_) {
    isEnd_ = true;
    UAnimInstance *animInstance = GetAnimInstance();
    animInstance->Montage_Play(endMontage_);
    FOnMontageEnded del;
    del.BindUObject(this, &UMultiAnimAbility::OnEndMontageEnded);
    animInstance->Montage_SetEndDelegate(del, endMontage_);
  }
}

void UMultiAnimAbility::DoAbility() {
  UAnimInstance *animInstance = GetAnimInstance();
  // モンタージュを再生
  animInstance->Montage_Play(startMontage_);
  FOnMontageEnded del;
  del.BindUObject(this, &UMultiAnimAbility::OnStartMontageEnded);
  animInstance->Montage_SetEndDelegate(del, startMontage_);
}

void UMultiAnimAbility::OnStartMontageEnded(UAnimMontage *montage,
                                            bool interrupted) {
  if (!interrupted) {
    UAnimInstance *animInstance = GetAnimInstance();
    animInstance->Montage_Play(loopMontage_);
  }
}

void UMultiAnimAbility::OnEndMontageEnded(UAnimMontage *montage,
                                          bool interrupted) {
  isEnd_ = false;
  if (!interrupted) {
    EndAbility();
  }
}

UAnimInstance *UMultiAnimAbility::GetAnimInstance() {
  ACharacter *character = Cast<ACharacter>(owner_->GetOwner());
  return character->GetMesh()->GetAnimInstance();
}
