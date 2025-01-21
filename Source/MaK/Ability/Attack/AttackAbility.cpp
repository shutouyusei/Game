#include "AttackAbility.h"
#include "AttackCollision.h"
#include "Components/ShapeComponent.h"
#include "Damage.h"
#include "GameFramework/Actor.h"
#include "StatsComponent.h"

AttackAbility::AttackAbility(UAnimInstance *animInstance,
                             UAnimMontage *animMontage,
                             AAttackCollision *collision, StatsBase *stats)
    : Ability(animInstance, animMontage) {
  collision_ = collision;
  stats_ = stats;
}

AttackAbility::~AttackAbility() {
  // Destructor
}

//
void AttackAbility::DoAbility(FTransform transform) {
  // Attack the target
  std::function<void(AActor *)> delegate_ =
      std::bind(&AttackAbility::AbilityDelegate, this, std::placeholders::_1);
  collision_->SetAbility(delegate_);
  PlayMontage();
  // Check if the collision is valid
}

void AttackAbility::OnMontageEnded(UAnimMontage *montage, bool bInterrupted) {
  // Check if the montage is interrupted
  collision_->DeleteAbility();
}

void AttackAbility::AbilityDelegate(AActor *otherActor) {
  // Delegate the ability
  if (otherActor->ActorHasTag("Game")) {
    StatsComponent statsComponent;
    StatsManager *statsManager = statsComponent.GetStatsManager();
    StatsBase *otherStats = statsManager->GetStats(otherActor);
    Damage::ApplyDamage(stats_, otherStats, 10.0f);
  }
}
