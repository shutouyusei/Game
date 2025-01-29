#include "DodgeAttack1.h"

DodgeAttack1::DodgeAttack1(AActor *owner, UAnimInstance *animInstance,
                           AAttackCollision *collision)
    : AttackAbility(owner, animInstance, collision) {
  // Set up the attack ability
  UAnimMontage *animMontage = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_DodgeAttack1.AM_DodgeAttack1"));

  FDamageStruct damage = {10.0, EDamageType::Physical,
                          EDamageElementType::None};

  SetUpAttackAbility(animMontage, damage);
}
