#include "Skill.h"
#include "SkillManager/SkillExecutionManager.h"

USkill::~USkill() {
  manager_ = nullptr;
}

bool USkill::can_activate() {
  return true;
}
