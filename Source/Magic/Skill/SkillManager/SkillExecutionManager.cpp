#include "SkillExecutionManager.h"
#include "../Skill.h"

void USkillExecutionManager::ExecuteSkill(USkill *skill) {
  switch (ability_flag_) {
  case ESkillFlag::None: {
    ActivateSkill(skill);
    break;
  }
  case ESkillFlag::CanNextAbility: {
    ActivateSkill(skill);
    break;
  }
  case ESkillFlag::CanInput: {
    next_skill_ = skill;
    break;
  }
  case ESkillFlag::Playing: {
    break;
  }
  }
}

void USkillExecutionManager::FinishSkill() {
  current_skill_ = nullptr;
  SetSkillFlag(ESkillFlag::None);
}

void USkillExecutionManager::ActivateSkill(USkill *skill) {
  next_skill_ = nullptr;
  current_skill_ = skill;
  skill->Activate();
}

void USkillExecutionManager::SetSkillFlag(ESkillFlag flag) {
  ability_flag_ = flag;
  switch (ability_flag_) {
  case ESkillFlag::None: {
    can_jump_ = true;
    break;
  }
  case ESkillFlag::CanNextAbility: {
    if (next_skill_ != nullptr) {
      ExecuteSkill(next_skill_);
    }
  }
  case ESkillFlag::CanInput: {
    break;
  }
  case ESkillFlag::Playing: {
    can_jump_ = false;
    break;
  }
  }
}
