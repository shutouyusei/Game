#include "Ability.h"

void UAbility::BeginPlay(TObjectPtr<UAbilityManager> manager) {
  manager_ = manager;
}

void UAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  manager_ = nullptr;
}

void UAbility::DoAbility() {
  for (UAbilityModifier *modifier : modifiers_) {
    modifier->AbiltiyMod(manager_);
  }
}

void UAbility::EndAbility() {
  if (manager_) {
    manager_->EndCurrentAbility();
  }
}
