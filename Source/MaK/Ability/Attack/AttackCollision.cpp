#include "AttackCollision.h"

#include "AttackAbility.h"

AAttackCollision::AAttackCollision() {
  // default can't overlap
  SetActorEnableCollision(false);
  // create the collision mesh
  collisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision Mesh"));
  // collision settings
  collisionMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
  collisionMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
  collisionMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

AAttackCollision::~AAttackCollision() {
  ability_delegate_.Unbind();
}

void AAttackCollision::NotifyActorBeginOverlap(AActor *otherActor) {
  // Deal damage to the enemy
  ability_delegate_.ExecuteIfBound(otherActor);
}

void AAttackCollision::DeleteAbility() { 
  ability_delegate_.Unbind(); 
}
