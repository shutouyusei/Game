#include "AbilityManager.h"
#include "AbilityNotify.h"

UAbilityManager::UAbilityManager() {}

UAbilityManager::~UAbilityManager() {
  for (Ability *ability : abilities_) {
    delete ability;
    ability = nullptr;
  }
  abilities_.Empty();
}

void UAbilityManager::SetAbility(int index, Ability *ability) {
  if (index < abilities_.Num()) {
    abilities_[index] = ability;
  } else {
    UE_LOG(LogTemp, Error,
           TEXT("UAbilityManager::SetAbility: Index out of range"));
  }
}

void UAbilityManager::AddAbility(Ability *ability) { abilities_.Add(ability); }

void UAbilityManager::ExecuteAbility(int index) {
  if (index >= abilities_.Num()) {
    UE_LOG(LogTemp, Error,
           TEXT("UAbilityManager::ExecuteAbility: Index out of range"));
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
    currentAbilityIndex_ = index;
    abilities_[currentAbilityIndex_]->DoAbility();
  }
}
