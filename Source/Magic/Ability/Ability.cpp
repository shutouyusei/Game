#include "Ability.h"

void UAbility::BeginPlay(TObjectPtr<UAbilityManager> manager) {
  manager_ = manager;
}

void UAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  manager_ = nullptr;
}

void UAbility::DoAbility() {}

void UAbility::EndAbility() {
  if (manager_) {
    manager_->EndCurrentAbility();
  }
}
