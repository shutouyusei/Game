#include "AttackAbility.h"
#include "Damage.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "StatusComponent.h"

void UAttackAbility::DoAbility() {
  // Play the attack animation
  PlayMontage();
  manager_->attack_collision_->ability_delegate_.BindUObject(this, &UAttackAbility::OnAttack);
}

void UAttackAbility::EndAbility() {
  manager_->attack_collision_->DeleteAbility();
  UAnimAbility::EndAbility();
}

void UAttackAbility::OnAttack(AActor *otherActor) {
  // actor is not me and is not null
  if (otherActor == nullptr || otherActor == manager_->GetOwner())
    return;
  // Get the stats component of the enemy
  UStatusComponent *applyier = manager_->GetOwner()->FindComponentByClass<UStatusComponent>();
  UStatusComponent *target = otherActor->FindComponentByClass<UStatusComponent>();
  // Apply the damage
  if (applyier != nullptr && target != nullptr)
    UDamage::ApplyDamage(applyier, target, damage_);
}
