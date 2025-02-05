#include "AttackAbility.h"
#include "AbilityManager.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "StatsComponent.h"

UAttackAbility::UAttackAbility() : UAnimAbility() {}

void UAttackAbility::DoAbility() {
  // Play the attack animation
  PlayMontage();
  owner_->attackCollision_->SetAbility([this](AActor *otherActor) {
    // Get the stats component of the enemy
    UE_LOG(LogTemp, Warning, TEXT("%s"), *otherActor->GetName());
  });
}

void UAttackAbility::EndAbility() {
  owner_->attackCollision_->DeleteAbility();
  UAnimAbility::EndAbility();
}
