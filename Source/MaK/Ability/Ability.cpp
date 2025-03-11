#include "Ability.h"
#include "AbilityManager.h"

UAbility::UAbility() : owner_(nullptr) {}

void UAbility::BeginPlay() {}

void UAbility::Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
  UE_LOG(LogTemp, Warning, TEXT("Tick in Base"));
}

void UAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  owner_ = nullptr;
}

void UAbility::SetOwner(UAbilityManager *owner) { owner_ = owner; }

void UAbility::DoAbility() {
  UE_LOG(LogTemp, Warning, TEXT("DoAbility in Base"));
  EndAbility();
}

void UAbility::EndAbility() {
  if (owner_) {
    owner_->End();
  }
}
