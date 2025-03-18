#pragma once

#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

class MontagePlayer {
public:
  static void PlayMontage(UAnimInstance *anim_instance, UAnimMontage *montage, FOnMontageEnded delegate);
};
