#include "AttackAbility.h"
#include "AbilityManager.h"
#include "AttackCollision.h"
#include "StatsComponent.h"

UAttackAbility::UAttackAbility() : UAnimAbility() {}

void UAttackAbility::DoAbility() {
  // Play the attack animation
  PlayMontage();
}

void UAttackAbility::EndAbility() { UAnimAbility::EndAbility(); }
// TODO:AttackCollisionの設定
