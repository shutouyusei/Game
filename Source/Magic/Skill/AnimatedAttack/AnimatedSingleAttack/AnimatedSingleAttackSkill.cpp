#include "AnimatedSingleAttackSkill.h"

UAnimatedSingleAttackSkill::~UAnimatedSingleAttackSkill() {
  attack_module_->montage_ = nullptr;
  attack_module_ = nullptr;
}

