#include "SkillManager.h"
#include "../SkillFactory.h"
#include "SkillExecutionManager.h"

USkillManager::USkillManager() {
  PrimaryComponentTick.bCanEverTick = true;
}

void USkillManager::BeginPlay() {
  for (auto &skill_factory : skill_factories_) {
    USkill *skill = skill_factory->Create();
    skill->manager_ = this;
    skill->BeginPlay();
    // スキル配列に追加
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
  }
}
