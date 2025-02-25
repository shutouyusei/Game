#include "InputAbility.h"

void UInputAbility::BeginPlay() {
  // Create the ability
  Ability_ = NewObject<UAbility>(this, InputAbility_);
  Ability_->SetOwner(owner_);
  Ability_->BeginPlay();
}

void UInputAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Ability_->EndPlay(EndPlayReason);
  Ability_->ConditionalBeginDestroy();
}

void UInputAbility::DoAbility() {
  //Input情報から向きを決める

  //DoAbility
  Ability_->DoAbility();
}
