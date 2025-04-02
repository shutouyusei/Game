#include "Skill.h"
#include "SkillManager/SkillExecutionManager.h"

void USkill::Deactivate() {
  manager_->execution_manager_->FinishSkill();
}

bool USkill::can_activate() {
  return true;
}
