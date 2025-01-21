#include "CoreMinimal.h"
#include "NormalAttakck.h"

Ability *NormalAttackFactory::CreateAbility(UAnimInstance *animInstance) {
  UAnimMontage *animMontage = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack1.AM_Attack1"));

  FDamageStruct damage = {10.0, EDamageType::Physical,
                          EDamageElementType::None};
return new AttackAbility(animInstance, animMontage, weapon_, stats_,damage);
}
