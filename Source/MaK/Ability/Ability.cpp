#include "Ability.h"
#include "AbilityManager.h"

UAbility::UAbility() : owner_(nullptr) {}

//NOTE: call by Ability Manager when set ability
void UAbility::SetOwner(UAbilityManager *owner) { owner_ = owner; }


void UAbility::DoAbility() {
}

void UAbility::EndAbility() {
  if (owner_) {
    owner_->End();
  }
}
