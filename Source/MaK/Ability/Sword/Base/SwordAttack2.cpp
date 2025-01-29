#include "SwordAttack2.h"

SwordAttack2::SwordAttack2(AActor *owner, UAnimInstance *animInstance,
                           AAttackCollision *collision)
    : AttackAbility(owner, animInstance, collision) {
  // Set up the attack ability
  UAnimMontage *animMontage = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack2.AM_Attack2"));

  FDamageStruct damage = {10.0, EDamageType::Physical,
                          EDamageElementType::None};

  SetUpAttackAbility(animMontage, damage);
}
