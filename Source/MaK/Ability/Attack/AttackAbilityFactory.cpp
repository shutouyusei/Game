#include "AttackAbilityFactory.h"
#include "AttackAbility.h"
#include "CoreMinimal.h"

Ability *AttackFactory::CreateAbility(UAnimInstance *animInstance) {
  return new AttackAbility(animInstance, animMontage_, owner_, weapon_,
                           damage_);
}
