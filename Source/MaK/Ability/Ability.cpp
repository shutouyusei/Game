#include "Ability.h"
#include "AbilityManager.h"

UAbility::UAbility() : manager_(nullptr) {}

void UAbility::BeginPlay() {}

void UAbility::Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {}

void UAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  manager_ = nullptr;
}

void UAbility::SetOwner(UAbilityManager *owner) { manager_ = owner; }

void UAbility::DoAbility() {
  UE_LOG(LogTemp, Warning, TEXT("DoAbility in Base"));
  EndAbility();
}

void UAbility::EndAbility() {
  if (manager_) {
    manager_->End();
  }
}
