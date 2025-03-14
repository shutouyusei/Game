#include "Ability.h"

void UAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  manager_ = nullptr;
}

void UAbility::SetManager(UAbilityManager *owner) { manager_ = owner; }

void UAbility::DoAbility() {
  EndAbility();
}

void UAbility::EndAbility() {
  if (manager_) {
    manager_->EndCurrentAbility();
  }
}
