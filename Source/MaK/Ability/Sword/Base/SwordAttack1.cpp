#include "SwordAttack1.h"

SwordAttack1::SwordAttack1(AActor *owner, UAnimInstance *animInstance,
                           AAttackCollision *collision)
    : AttackAbility(owner, animInstance, collision) {
  // Set up the attack ability
  UAnimMontage *animMontage = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack1.AM_Attack1"));

  FDamageStruct damage = {10.0, EDamageType::Physical,
                          EDamageElementType::None};

  SetUpAttackAbility(animMontage, damage);
}
