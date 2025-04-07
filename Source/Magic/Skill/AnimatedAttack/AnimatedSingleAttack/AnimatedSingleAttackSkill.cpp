#include "AnimatedSingleAttackSkill.h"

UAnimatedSingleAttackSkill::~UAnimatedSingleAttackSkill() {
  attack_module_ = nullptr;
}

void UAnimatedSingleAttackSkill::OnAttack(ACharacter *target) {
}
