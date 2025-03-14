#include "ComboAbility.h"

void UComboAbility::BeginPlay() {
  for (TSubclassOf<UAbility> &abilityClass : comboAbilities_) {
    UAbility *ability = NewObject<UAbility>(this, abilityClass);
    ability->SetManager(manager_);
    ability->BeginPlay();
    abilityInstances_.Add(ability);
  }
}

void UComboAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  for (UAbility *ability : abilityInstances_) {
    ability->EndPlay(EndPlayReason);
    ability->ConditionalBeginDestroy();
  }
  abilityInstances_.Empty();
}

void UComboAbility::DoAbility() {
  if (abilityInstances_.Num() == 0)
    return;
  abilityInstances_[currentAbilityIndex_]->DoAbility();
  currentAbilityIndex_ = (currentAbilityIndex_ + 1) % comboAbilities_.Num();
}
