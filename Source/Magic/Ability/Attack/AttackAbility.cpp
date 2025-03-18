#include "AttackAbility.h"
#include "Damage.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "StatusComponent.h"

void UAttackAbility::DoAbility() {
  // Play the attack animation
  PlayMontage();
}

void UAttackAbility::EndAbility() {
  UAnimAbility::EndAbility();
}
