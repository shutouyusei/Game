#include "MontagePlayer.h"
#include "Animation/AnimMontage.h"

void UMontagePlayer::PlayMontage(UAnimInstance *anim_instance,FOnMontageEnded delegate) {
  if (montage_ && anim_instance) {
    anim_instance->Montage_Play(montage_);
    anim_instance->Montage_SetEndDelegate(delegate, montage_);
  }
}
