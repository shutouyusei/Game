#include "AttackCollision.h"
#include <functional>

void AAttackCollision::NotifyActorBeginOverlap(AActor *otherActor) {
  // Check if the other actor is an enemy
  if (bCanDealDamage_) {
    // Deal damage to the enemy
    if (AbilityDelegate_ != nullptr)
      AbilityDelegate_(otherActor);
  }
}

void AAttackCollision::SetAbility(
    std::function<void(AActor *)> AbilityDelegate) {
  AbilityDelegate_ = AbilityDelegate;
  bCanDealDamage_ = true;
}

void AAttackCollision::DeleteAbility() {
  AbilityDelegate_ = nullptr;
  bCanDealDamage_ = false;
}
