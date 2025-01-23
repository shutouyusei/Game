#include "AttackAbilityFactory.h"
#include "CoreMinimal.h"

Ability *AttackFactory::CreateAbility(UAnimInstance *animInstance) {
  return new AttackAbility(animInstance, animMontage_, weapon_, stats_,
                           damage_);
}
