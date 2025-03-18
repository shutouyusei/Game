#include "Ability.h"

void UAbility::BeginPlay(TObjectPtr<UAbilityManager> manager) {
  for (TSubclassOf<UAbilityModifier> &modifier : modifiers_) {
    modifiers_instance_.Add(NewObject<UAbilityModifier>(this, modifier));
  }
  manager_ = manager;
}

void UAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  modifiers_instance_.Empty();
  manager_ = nullptr;
}

void UAbility::DoAbility() {
  for (UAbilityModifier *modifier : modifiers_instance_) {
    modifier->AbilityMod(manager_);
  }
}

void UAbility::EndAbility() {
  if (manager_) {
    manager_->EndCurrentAbility();
  }
}
