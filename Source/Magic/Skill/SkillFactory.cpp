#include "SkillFactory.h"

USkill *USkillFactory::Create(int32 level, USkillManager *manager) {
  // USkill *skill = NewObject<USkill>();
  // skill->manager_ = manager;
  // return skill;
  return nullptr;
}

FSkillData USkillFactory::get_skill_data(int32 level) {
  switch (level) {
  case 1:
    return level1_data;
  case 2:
    return level2_data;
  case 3:
    return level3_data;
  default:
    return FSkillData();
  }
}
