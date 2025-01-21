#include "AttackCollision.h"
#include "Animation/AnimMontage.h"
#include "AttackAbility.h"
#include "StatsBase.h"

void AAttackCollision::NotifyActorBeginOverlap(AActor *otherActor) {
  // Check if the other actor is an enemy
  if (bCanDealDamage) {
    // Deal damage to the enemy
    AbilityDelegate_(otherActor);
  }
}

void AAttackCollision::SetAbility(
    std::function<void(AActor *)> AbilityDelegate) {
  AbilityDelegate_ = AbilityDelegate;
  bCanDealDamage = true;
}

void AAttackCollision::DeleteAbility() {
  AbilityDelegate_ = nullptr;
  bCanDealDamage = false;
}
