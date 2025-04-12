#include "AnimatedAttack.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

void UAnimatedAttack::Attack() {
  anim_instance_->Montage_Play(montage_);
  FOnMontageEnded delegate;
  delegate.BindUObject(this, &UAnimatedAttack::OnAttackEnd);
  anim_instance_->Montage_SetEndDelegate(delegate, montage_);
}

void UAnimatedAttack::OnAttackEnd(UAnimMontage *montage, bool interrupted) {
  on_attack_end_.ExecuteIfBound(montage, interrupted);
}

void UAnimatedAttack::OnAttack(ACharacter *target) {
  // damage
  // damage_info
  // call back
  on_attack_.ExecuteIfBound(target);
}
