#include "MontagePlayer.h"

void MontagePlayer::PlayMontage(UAnimInstance *anim_instance, UAnimMontage *montage, FOnMontageEnded delegate) {
  if (montage && anim_instance) {
    anim_instance->Montage_Play(montage);
    anim_instance->Montage_SetEndDelegate(delegate, montage);
  }
}
