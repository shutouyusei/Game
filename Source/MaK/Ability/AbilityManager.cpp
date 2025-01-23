#include "AbilityManager.h"
#include "Ability.h"
#include "AbilityNotify.h"

AbilityManager::AbilityManager(TArray<Ability *> abilities)
    : abilities_(abilities) {
  for (auto ability : abilities_) {
  }
}

AbilityManager::~AbilityManager() {}

void AbilityManager::ExecuteAbility(int index) {
  Ability *ability = abilities_[index];
  if (canInput_) {
    if (isExecuting_) {
      nextAbilityIndex_ = index;
      return;
    }
    ability->SetAnimNotifyDelegate( FName("RejectInput"), [this]() { canInput_ = false; }, [this]() { canInput_ = true; });

    ability->SetAnimNotifyDelegate( FName("Ability"), [this]() { isExecuting_ = true; }, [this]() { EndAbility(); });

    currentAbilityIndex_ = index;
    abilities_[index]->DoAbility();
  }
}

void AbilityManager::EndAbility() {
  isExecuting_ = false;
  Ability *ability = abilities_[currentAbilityIndex_];

  ability->SetAnimNotifyDelegate( FName("RejectInput"),nullptr ,nullptr );

  ability->SetAnimNotifyDelegate( FName("Ability"),nullptr ,nullptr);

  if (nextAbilityIndex_ != -1) {
    ExecuteAbility(nextAbilityIndex_);
    nextAbilityIndex_ = -1;
  }
}
