#include "Ability.h"

Ability::Ability(UAnimInstance *animInstance, UAnimMontage *animMontage)
    : animInstance_(animInstance), animMontage_(animMontage) {
}

void Ability::OnMontageEnded(UAnimMontage *montage, bool bInterrupted) {
  // Check if the montage is interrupted
  UE_LOG(LogTemp, Warning, TEXT("Montage ended in base"));
}
void Ability::PlayMontage() {
  animInstance_->Montage_Play(animMontage_);
  //NOTE:モンタージュ再生後でしかdelegateの設定ができない！！
  //こんなのしるか
  FOnMontageEnded endDelegate;
  endDelegate.BindRaw(this, &Ability::OnMontageEnded);
  animInstance_->Montage_SetEndDelegate(endDelegate, animMontage_);
}
