#include "AttackAbility.h"
#include "AttackCollision.h"
#include "Components/ShapeComponent.h"
#include "GameFramework/Actor.h"

AttackAbility::AttackAbility(UAnimInstance *animInstance,
                             UAnimMontage *animMontage,
                             AAttackCollision *collision)
    : Ability(animInstance, animMontage) {
  collision_ = collision;
  delegate_ = std::bind(&AttackAbility::AbilityDelegate, this, std::placeholders::_1);
}

AttackAbility::~AttackAbility() {
  // Destructor
}

void AttackAbility::DoAbility(FTransform transform) {
  // Attack the target
  collision_->SetAbility(delegate_);
  PlayMontage();
  // Check if the collision is valid
}

void AttackAbility::OnMontageEnded(UAnimMontage *montage, bool bInterrupted) {
  // Check if the montage is interrupted
  UE_LOG(LogTemp, Warning, TEXT("Montage ended"));
  collision_->DeleteAbility();
}

void AttackAbility::AbilityDelegate(AActor *otherActor) {
  // Delegate the ability
  UE_LOG(LogTemp, Warning, TEXT("Delegate the ability"));
  //Actor name
  UE_LOG(LogTemp, Warning, TEXT("Actor name: %s"), *otherActor->GetName());
}
