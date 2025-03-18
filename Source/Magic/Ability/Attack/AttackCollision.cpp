#include "AttackCollision.h"
#include "Damage.h"
#include "StatusComponent.h"
#include <functional>

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
  ability_delegate_ = nullptr;
}

void AAttackCollision::StartAttack(AActor *applyier, FDamageStruct damage) {
  ability_delegate_ = [applyier, damage](AActor *otherActor) {
    // Deal damage to the enemy
    if (otherActor == nullptr || otherActor == applyier)
      return;
    // Get the stats component of the enemy
    UStatusComponent *applyier_status = applyier->FindComponentByClass<UStatusComponent>();
    UStatusComponent *target_status = otherActor->FindComponentByClass<UStatusComponent>();
    // Apply the damage
    if (applyier_status != nullptr && target_status != nullptr)
      UDamage::ApplyDamage(applyier_status, target_status, damage);
  };
}

void AAttackCollision::EndAttack() {
  ability_delegate_ = nullptr;
}

void AAttackCollision::NotifyActorBeginOverlap(AActor *otherActor) {
  // Deal damage to the enemy
  if (ability_delegate_ != nullptr) {
    ability_delegate_(otherActor);
  }
}
