#include "SkillManager.h"
#include "../SkillFactory.h"

USkillManager::USkillManager() {
  PrimaryComponentTick.bCanEverTick = true;
}

void USkillManager::ExecuteSkill(int index) {
  if (index < 0 || index >= skills_.Num()) {
    UE_LOG(LogTemp, Warning, TEXT("Invalid skill index"));
    UE_LOG(LogTemp, Warning, TEXT("Index: %d"), skills_.Num());
    return;
  }
  USkill *skill = skills_[index];
  if (skill) {
    execution_manager_->ExecuteSkill(skill);
  } else {
    UE_LOG(LogTemp, Warning, TEXT("Skill not found"));
  }
}

void USkillManager::BeginPlay() {
  for (auto &skill_factory_class : skill_factories_) {
    USkillFactory *skill_factory = NewObject<USkillFactory>(this, skill_factory_class);
    USkill *skill = skill_factory->Create(this);
    skill->BeginPlay();
    // スキル配列に追加
    UE_LOG(LogTemp, Warning, TEXT("Skill %s"), *skill->GetName());
    skills_.Add(skill);
  }
  // execution_manager_
  execution_manager_ = NewObject<USkillExecutionManager>(this);
}

void USkillManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
  if (execution_manager_->get_current_skill() != nullptr) {
    execution_manager_->get_current_skill()->Tick(DeltaTime);
  }
}

void USkillManager::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  for (auto &skill : skills_) {
    skill->EndPlay();
    skill = nullptr;
  }
  skills_.Empty();
}
