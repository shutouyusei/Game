#include "SwordAttack3.h"

SwordAttack3::SwordAttack3(AActor *owner, UAnimInstance *animInstance,
                           AAttackCollision *collision)
    : AttackAbility(owner, animInstance, collision) {
  // Set up the attack ability
  UAnimMontage *animMontage = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack3.AM_Attack3"));

  FDamageStruct damage = {10.0, EDamageType::Physical,
                          EDamageElementType::None};

  SetUpAttackAbility(animMontage, damage);
}
