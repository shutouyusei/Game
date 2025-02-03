#include "AttackCollision.h"
#include "AttackAbility.h"
#include "Components/StaticMeshComponent.h"
#include <functional>

AAttackCollision::AAttackCollision() {
  CollisionMesh =
      CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollisionMesh"));
  // collision preset overlap all
  CollisionMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
  CollisionMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
  CollisionMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
  RootComponent = CollisionMesh;
}

AAttackCollision::~AAttackCollision() {
  if (AbilityDelegate_ != nullptr)
    AbilityDelegate_ = nullptr;
}

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
