#include "Skill.h"
#include "SkillManager/SkillExecutionManager.h"

USkill::~USkill() {
  manager_ = nullptr;
}

void USkill::SetSkillData(FSkillData data) {
  skill_data_ = data;
}

bool USkill::can_activate() {
  return true;
}
