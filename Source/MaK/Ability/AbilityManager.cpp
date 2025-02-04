#include "AbilityManager.h"
#include "AbilityNotify.h"

UAbilityManager::UAbilityManager() {}

UAbilityManager::~UAbilityManager() {}

void UAbilityManager::BeginPlay() {
  for (UAbility *ability : abilities_) {
    ability->SetOwner(this);
  }
}

void UAbilityManager::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  for (UAbility *ability : abilities_) {
    ability->SetOwner(nullptr);
  }
}

void UAbilityManager::SetAbility(int index, UAbility *ability) {
  if (index < abilities_.Num()) {
    abilities_[index] = ability;
  } else {
    UE_LOG(LogTemp, Error,
           TEXT("UAbilityManager::SetAbility: Index out of range"));
  }
}


void UAbilityManager::Execute(int index) {
  // Check can do ability
  if(!canInput_) {
    return;
  }
  //Check if doing ability
  if(currentAbilityIndex_ != -1) {
    //push ability queue
    nextAbilityIndex_ = index;
    if(canNextAbility_) {
      ExecuteNext();
    }
    return;
  }
  // Execute ability
  if(index < abilities_.Num()) {
    canInput_ = false;
    canNextAbility_ = false;
    currentAbilityIndex_ = index;
    abilities_[currentAbilityIndex_]->DoAbility();
  } else {
    UE_LOG(LogTemp, Error, TEXT("UAbilityManager::ExecuteAbility: Index out of range"));
  }
}

void UAbilityManager::End() {
  currentAbilityIndex_ = -1;
}

void UAbilityManager::ExecuteNext() {
  abilities_[currentAbilityIndex_]->EndAbility();
  int index = nextAbilityIndex_;
  nextAbilityIndex_ = -1;
  Execute(index);
}

void UAbilityManager::CanInput() { canInput_ = true; }

void UAbilityManager::CanNextAbility() {
  canNextAbility_ = true;
  if(nextAbilityIndex_ != -1) {
    ExecuteNext();
  } 
}

