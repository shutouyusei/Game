#include "AbilityManager.h"
#include "Ability.h"

UAbilityManager::UAbilityManager() {
  // Tickのための設定
  PrimaryComponentTick.bCanEverTick = true;
  bAutoActivate = true;
  SetComponentTickEnabled(true);
}

void UAbilityManager::SetupAbilityManager(AAttackCollision *attack_collision) {
  attack_collision_ = attack_collision;
}

void UAbilityManager::BeginPlay() {
  Super::BeginPlay();
  // make abilities
  for (TSubclassOf<UAbility> &ability_class : ability_classes_) {
    UAbility *ability = nullptr;
    if (ability_class != nullptr) {
      ability = NewObject<UAbility>(this, ability_class);
    } else {
      ability = NewObject<UAbility>(this, UAbility::StaticClass());
    }
    ability->SetManager(this);
    ability->BeginPlay();
    ability_instances_.Add(ability);
  }
}

void UAbilityManager::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Super::EndPlay(EndPlayReason);
  // delete array of ability instances
  for (UAbility *ability : ability_instances_) {
    // delete ability ability instance
    ability->EndPlay(EndPlayReason);
  }
  ability_instances_.Empty();
}

void UAbilityManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
  // current_ability_index_ の値
  if (current_ability_index_ != -1) {
    ability_instances_[current_ability_index_]->Tick(DeltaTime, TickType, ThisTickFunction);
  }
}

void UAbilityManager::SetAbility(int index, UAbility *ability) {
  if (index < ability_instances_.Num()) {
    ability_instances_[index] = ability;
  } else {
    UE_LOG(LogTemp, Error,
           TEXT("UAbilityManager::SetAbility: Index out of range"));
  }
}

// WARN:原因不明だがフラグが治らなくなるバグがたまに発生している
// OnMontageEndedのフラグの設定後にバグが発生するようになった
void UAbilityManager::Execute(int index) {
  switch (ability_flag_) {
  case EAbilityFlag::None: {
    ability_flag_ = EAbilityFlag::Playing;
    ExecuteAbility(index);
    UE_LOG(LogTemp, Warning, TEXT("ability"));
    break;
  }
  case EAbilityFlag::CanNextAbility: {
    ability_flag_ = EAbilityFlag::Playing;
    ExecuteAbility(index);
    UE_LOG(LogTemp, Warning, TEXT("can next ability"));
    break;
  }
  case EAbilityFlag::CanInput: {
    next_ability_index_ = index;
    UE_LOG(LogTemp, Warning, TEXT("can input"));
    break;
  }
  case EAbilityFlag::Playing: {
    break;
  }
  }
}
// Execute ability
void UAbilityManager::ExecuteAbility(int index) {
  if (0 <= index && index < ability_instances_.Num()) {
    current_ability_index_ = index;
    ability_instances_[current_ability_index_]->DoAbility();
  } else {
    UE_LOG(LogTemp, Error, TEXT("UAbilityManager::ExecuteAbility: Index out of range"));
  }
}

void UAbilityManager::EndCurrentAbility() {
  SetAbilityFlag(EAbilityFlag::None);
  current_ability_index_ = -1;
}

void UAbilityManager::ExecuteNext() {
  if (next_ability_index_ != -1) {
    ability_instances_[current_ability_index_]->EndAbility();
    Execute(next_ability_index_);
    next_ability_index_ = -1;
  }
}

void UAbilityManager::SetAbilityFlag(EAbilityFlag flag) {
  ability_flag_ = flag;
}
