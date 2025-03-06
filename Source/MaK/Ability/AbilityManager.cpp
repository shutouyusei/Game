#include "AbilityManager.h"

UAbilityManager::UAbilityManager() {}

UAbilityManager::~UAbilityManager() {}

void UAbilityManager::SetupAbilityManager(AAttackCollision *attackCollision) {
  attackCollision_ = attackCollision;
}
void UAbilityManager::BeginPlay() {
  Super::BeginPlay();
  // make abilities
  for (TSubclassOf<UAbility> &abilityClass : abilities_) {
    UAbility *ability = nullptr;
    if (abilityClass != nullptr) {
      ability = NewObject<UAbility>(this, abilityClass);
    } else {
      ability = NewObject<UAbility>(this, UAbility::StaticClass());
    }
    ability->SetOwner(this);
    ability->BeginPlay();
    abilityInstances_.Add(ability);
  }
}

void UAbilityManager::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Super::EndPlay(EndPlayReason);
  // delete array of ability instances
  for (UAbility *ability : abilityInstances_) {
    // delete ability ability instance
    ability->EndPlay(EndPlayReason);
  }
  abilityInstances_.Empty();
}

void UAbilityManager::SetAbility(int index, UAbility *ability) {
  if (index < abilityInstances_.Num()) {
    abilityInstances_[index] = ability;
  } else {
    UE_LOG(LogTemp, Error,
           TEXT("UAbilityManager::SetAbility: Index out of range"));
  }
}

void UAbilityManager::Execute(int index) {
  // Check can do ability
  if (!canInput_) {
    UE_LOG(LogTemp, Warning, TEXT("cant input"));
    return;
  }
  // Check can next ability
  if (!canNextAbility_) {
    UE_LOG(LogTemp, Warning, TEXT("can next ability"));
    nextAbilityIndex_ = index;
    return;
  }
  // Execute ability
  // NOTE:UPROPERTYが原因かも後で検証
  if (index < abilityInstances_.Num() && index >= 0) {
    UE_LOG(LogTemp, Warning, TEXT("ability"));
    canInput_ = false;
    canNextAbility_ = false;
    currentAbilityIndex_ = index;
    nextAbilityIndex_ = -1;
    abilityInstances_[currentAbilityIndex_]->DoAbility();
  } else {
    UE_LOG(LogTemp, Error,
           TEXT("UAbilityManager::ExecuteAbility: Index out of range"));
  }
}

void UAbilityManager::End() {
  canInput_ = true;
  canNextAbility_ = true;
  currentAbilityIndex_ = -1;
}

void UAbilityManager::ExecuteNext() {
  UE_LOG(LogTemp, Warning, TEXT("ExecuteNext"));
  abilityInstances_[currentAbilityIndex_]->EndAbility();
  Execute(nextAbilityIndex_);
}

void UAbilityManager::CanInput() { 
  UE_LOG(LogTemp,Warning,TEXT("CanInput"))
  canInput_ = true; 
}

void UAbilityManager::CanNextAbility() {
  UE_LOG(LogTemp,Warning,TEXT("CanNextAbility"))
  canNextAbility_ = true;
  if (nextAbilityIndex_ != -1)
    ExecuteNext();
}
