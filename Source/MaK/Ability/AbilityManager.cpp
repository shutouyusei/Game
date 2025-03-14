#include "AbilityManager.h"

UAbilityManager::UAbilityManager() {
  PrimaryComponentTick.bCanEverTick = true;
  bAutoActivate = true;
  SetComponentTickEnabled(true);
}

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
    ability->SetManager(this);
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

void UAbilityManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
  // currentAbilityIndex_ の値
  if (currentAbilityIndex_ != -1) {
    abilityInstances_[currentAbilityIndex_]->Tick(DeltaTime, TickType, ThisTickFunction);
  }
}

void UAbilityManager::SetAbility(int index, UAbility *ability) {
  if (index < abilityInstances_.Num()) {
    abilityInstances_[index] = ability;
  } else {
    UE_LOG(LogTemp, Error,
           TEXT("UAbilityManager::SetAbility: Index out of range"));
  }
}

// WARN:原因不明だがフラグが治らなくなるバグがたまに発生している
// OnMontageEndedのフラグの設定後にバグが発生するようになった
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
  abilityInstances_[currentAbilityIndex_]->EndAbility();
  Execute(nextAbilityIndex_);
}

void UAbilityManager::CanInput() {
  canInput_ = true;
}

void UAbilityManager::CanNextAbility() {
  canNextAbility_ = true;
  if (nextAbilityIndex_ != -1)
    ExecuteNext();
}
