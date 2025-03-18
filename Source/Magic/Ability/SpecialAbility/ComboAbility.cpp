#include "ComboAbility.h"

void UComboAbility::BeginPlay(TObjectPtr<UAbilityManager> manager) {
  Super::BeginPlay(manager);
  for (TSubclassOf<UAbility> &ability_class : combo_abilities_) {
    if(ability_class == nullptr)
      continue;
    UAbility *ability = NewObject<UAbility>(this, ability_class);
    ability->BeginPlay(manager);
    ability_instances_.Add(ability);
  }
}

void UComboAbility::DoAbility() {
  if (ability_instances_.Num() == 0)
    return;
  ability_instances_[combo_index_]->DoAbility();
  combo_index_ = (combo_index_ + 1) % ability_instances_.Num();
}

void UComboAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  for (UAbility *ability : ability_instances_) {
    ability->EndPlay(EndPlayReason);
    ability->ConditionalBeginDestroy();
  }
  ability_instances_.Empty();
}
