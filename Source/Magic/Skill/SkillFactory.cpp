#include "SkillFactory.h"

USkill *USkillFactory::Create(int32 level, USkillManager *manager) {
  USkill *skill = CreateSkill(level, manager);
  if (skill == nullptr) {
    return nullptr;
  }
  skill->manager_ = manager;
  skill->level_ = level;
  skill->skill_data_ = get_skill_data(level);
  return skill;
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

USkill *USkillFactory::CreateSkill(int32 level, USkillManager *manger) {
  return nullptr;
}
