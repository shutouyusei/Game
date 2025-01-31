#include "AttackAbility.h"
#include "AttackCollision.h"
#include "StatsComponent.h"
#include "AbilityManager.h"

AttackAbility::AttackAbility(UAbilityManager *owner,
                             UAnimInstance *animInstance,
                             AAttackCollision *collision)
    : AbilityWithMontage(owner, animInstance), collision_(collision) {}

void AttackAbility::DoAbility() {
  // Play the attack animation
  isExecuting_ = true;
  PlayMontage();
}

void AttackAbility::EndAbility() {
  // Stop the attack animation
  isExecuting_ = false;
}

void AttackAbility::SetUpAttackAbility(UAnimMontage *animMontage,
                                       FDamageStruct damage) {
  // Set up the attack ability
  animMontage_ = animMontage;
  damage_ = damage;
  SetUpAbilityWithMontage();
  auto damageToEnemy = [this]() -> void {
    collision_->SetAbility([this](AActor *otherActor) {
      if (otherActor->ActorHasTag("Game")) {
        StatsComponent statsComponent;
        StatsManager *statsManager = statsComponent.GetStatsManager();
        AActor *owner = owner_->GetOwner();

        StatsBase *ownerStats = statsManager->GetStats(owner);
        StatsBase *otherStats = statsManager->GetStats(otherActor);

        Damage::ApplyDamage(ownerStats, otherStats, damage_);
      }
    });
  };

  auto endDelegate = [this]() -> void { collision_->DeleteAbility(); };

  SetAnimNotifyDelegate(TEXT("Attack"), damageToEnemy, endDelegate);
}
