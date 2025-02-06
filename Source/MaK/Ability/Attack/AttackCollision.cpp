#include "AttackCollision.h"
#include "AttackAbility.h"
#include <functional>

AAttackCollision::AAttackCollision() {
  // default can't overlap
  SetActorEnableCollision(false);
  // create the collision mesh
  collisionMesh =
      CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision Mesh"));
  // collision settings
  collisionMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
  collisionMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
  collisionMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
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

void AAttackCollision::DeleteAbility() { AbilityDelegate_ = nullptr; }
