#include "AbilityManager.h"
#include "Ability.h"
#include "AbilityNotify.h"

AbilityManager::AbilityManager() {}

AbilityManager::~AbilityManager() {
  for (Ability *ability : abilities_) {
    delete ability;
    ability = nullptr;
  }
  abilities_.Empty();
}

void AbilityManager::SetAbility(int index, Ability *ability) {
  if (index < abilities_.Num()) {
    abilities_[index] = ability;
  } else {
    UE_LOG(LogTemp, Error,
           TEXT("AbilityManager::SetAbility: Index out of range"));
  }
}

void AbilityManager::AddAbility(Ability *ability) { abilities_.Add(ability); }

void AbilityManager::ExecuteAbility(int index) {
  if (index >= abilities_.Num()) {
    UE_LOG(LogTemp, Error,
           TEXT("AbilityManager::ExecuteAbility: Index out of range"));
    return;
  }

  if (currentAbilityIndex_ == -1) {
    currentAbilityIndex_ = index;
    abilities_[currentAbilityIndex_]->DoAbility();
    return;
  }

  Ability *ability = abilities_[currentAbilityIndex_];
  if (ability->IsExecuting()) {
  } else {
    ability->EndAbility();
    currentAbilityIndex_ = index;
    abilities_[currentAbilityIndex_]->DoAbility();
  }
}
