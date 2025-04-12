#include "NormalSwordAttackFactory.h"
#include "../../../DamageInfo.h"
#include "../../AnimatedAttackFactory.h"
#include "GameFramework/Character.h"
#include "NormalSwordAttack.h"

USkill *UNormalSwordAttackFactory::Create(int32 level, USkillManager *manager) {
  // Create skill
  UNormalSwordAttack *skill = NewObject<UNormalSwordAttack>(manager);
  // create attack modules
  UAnimatedAttackFactory *attack_factory = NewObject<UAnimatedAttackFactory>();

  return nullptr;
}
