#include "AnimatedAttack.h"

void UAnimatedAttack::Attack() {
  anim_instance_->Montage_Play(montage_);
  FOnMontageEnded delegate;
  delegate.BindUObject(this, &UAnimatedAttack::OnAttackEnd);
  anim_instance_->Montage_SetEndDelegate(delegate, montage_);
}

void UAnimatedAttack::OnAttackEnd(UAnimMontage *montage, bool interrupted) {
}

void UAnimatedAttack::OnAttack(ACharacter *target) {
  UE_LOG(LogTemp, Warning, TEXT("Attack"));
  // damage
}
