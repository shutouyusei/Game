#include "AttackCollision.h"
#include "AttackAbility.h"
#include <functional>

AAttackCollision::AAttackCollision() {
  //default can't overlap
  SetActorEnableCollision(false);
}

AAttackCollision::~AAttackCollision() {
  if (AbilityDelegate_ != nullptr)
    AbilityDelegate_ = nullptr;
}

void AAttackCollision::NotifyActorBeginOverlap(AActor *otherActor) {
  // Deal damage to the enemy
  if (AbilityDelegate_ != nullptr)
    AbilityDelegate_(otherActor);
}

void AAttackCollision::SetAbility(
    std::function<void(AActor *)> AbilityDelegate) {
  AbilityDelegate_ = AbilityDelegate;
}

void AAttackCollision::DeleteAbility() {
  AbilityDelegate_ = nullptr;
}
