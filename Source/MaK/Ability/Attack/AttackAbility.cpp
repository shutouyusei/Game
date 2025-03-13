#include "AttackAbility.h"
#include "AbilityManager.h"
#include "Damage.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "StatusComponent.h"

UAttackAbility::UAttackAbility() : UAnimAbility() {}

void UAttackAbility::DoAbility() {
  // Play the attack animation
  PlayMontage();
  manager_->attackCollision_->SetAbility([this](AActor *otherActor) {
    // actor is not me and is not null
    if (otherActor == nullptr || otherActor == manager_->GetOwner())
      return;
    // Get the stats component of the enemy
    UStatusComponent *applyier =
        manager_->GetOwner()->FindComponentByClass<UStatusComponent>();
    UStatusComponent *target =
        otherActor->FindComponentByClass<UStatusComponent>();
    // Apply the damage
    if (applyier != nullptr && target != nullptr)
      UDamage::ApplyDamage(applyier, target, damage_);
  });
}

void UAttackAbility::EndAbility() {
  manager_->attackCollision_->DeleteAbility();
  UAnimAbility::EndAbility();
}
