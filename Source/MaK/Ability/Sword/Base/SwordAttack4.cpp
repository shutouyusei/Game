#include "SwordAttack4.h"

SwordAttack4::SwordAttack4(UAbilityManager *owner, UAnimInstance *animInstance,
                           AAttackCollision *collision)
    : AttackAbility(owner, animInstance, collision) {
  // Set up the attack ability
  UAnimMontage *animMontage = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack4.AM_Attack4"));

  FDamageStruct damage = {10.0, EDamageType::Physical,
                          EDamageElementType::None};

  SetUpAttackAbility(animMontage, damage);
}
