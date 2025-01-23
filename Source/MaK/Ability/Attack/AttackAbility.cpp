#include "AttackAbility.h"
#include "AttackCollision.h"
#include "Components/ShapeComponent.h"
#include "GameFramework/Actor.h"
#include "StatsComponent.h"

AttackAbility::AttackAbility(UAnimInstance *animInstance,
                             UAnimMontage *animMontage,
                             AAttackCollision *collision, StatsBase *stats,
                             FDamageStruct damage)
    : Ability(animInstance, animMontage) {
  collision_ = collision;
  stats_ = stats;
  damage_ = damage;

  for (auto notify : notifies_) {
    if (notify->Name == TEXT("Attack")) {
      UE_LOG(LogTemp, Warning, TEXT("Attack notify found"));
      notify_ = notify;
    }
  }
}

AttackAbility::~AttackAbility() {
  // Destructor
  notify_->SetDelegate(nullptr, nullptr);
}

//
void AttackAbility::DoAbility() {
  // Attack the target
  if(notify_ != nullptr) {
  notify_->SetDelegate([this]() { OnNotifyBegin(); },
                       [this]() { OnNotifyEnd(); });
  }
  //
  PlayMontage();
  // Check if the collision is valid
}

void AttackAbility::OnMontageEnded(UAnimMontage *montage, bool bInterrupted) {
  // Check if the montage is interrupted
  if(notify_ != nullptr) {
  notify_->SetDelegate(nullptr, nullptr);
  }
}

void AttackAbility::OnNotifyBegin() {
  // Check if the notify is beginning
  collision_->SetAbility([this](AActor *otherActor) {
    if (otherActor->ActorHasTag("Game")) {
      StatsComponent statsComponent;
      StatsManager *statsManager = statsComponent.GetStatsManager();
      StatsBase *otherStats = statsManager->GetStats(otherActor);
      Damage::ApplyDamage(stats_, otherStats, damage_);
    }
  });
}

void AttackAbility::OnNotifyEnd() {
  // Check if the notify is ending
  collision_->DeleteAbility();
}
