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
    UAbility *ability = NewObject<UAbility>(this, abilityClass);
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
    return;
  }
  // Check can next ability
  if (!canNextAbility_) {
    nextAbilityIndex_ = index;
    return;
  }
  // Execute ability
  // XXX :連続発動でcurrentAbilityIndex? =
  // -1となる場合がありエラーとなっている そのため-1か暫定的にチェックする
  // NOTE:UPROPERTYが原因かも後で検証
  if (index < abilityInstances_.Num() && index >= 0) {
    canInput_ = false;
    canNextAbility_ = false;
    currentAbilityIndex_ = index;
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
  // XXX:ここも同様
  // FIXME:多分エラーログ的にここのインデックスがバグってる可能性がある
  if (currentAbilityIndex_ >= 0 &&
      currentAbilityIndex_ < abilityInstances_.Num()) {
    abilityInstances_[currentAbilityIndex_]->EndAbility();
  }
  int index = nextAbilityIndex_;
  nextAbilityIndex_ = -1;
  Execute(index);
}

void UAbilityManager::CanInput() { canInput_ = true; }

void UAbilityManager::CanNextAbility() {
  canNextAbility_ = true;
  if (nextAbilityIndex_ < abilityInstances_.Num() && nextAbilityIndex_ >= 0)
    ExecuteNext();
}
