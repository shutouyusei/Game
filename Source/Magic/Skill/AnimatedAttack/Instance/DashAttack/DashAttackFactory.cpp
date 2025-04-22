#include "DashAttackFactory.h"
#include "../../../DamageInfo.h"
#include "../../AnimatedAttackFactory.h"
#include "DashAttack.h"
#include "GameFramework/Character.h"

USkill *UDashAttackFactory::CreateSkill(int32 level, USkillManager *manager) {
  // skill create
  UDashAttack *skill = NewObject<UDashAttack>(manager);
  // set data
  skill->attack_module_ = CreateAttackModule(manager, montage_, CreateDamageInfo(level));
  skill->owner_ = Cast<ACharacter>(manager->GetOwner());
  // set function
  SetSkillEffect(skill->attack_module_, skill, &UDashAttack::Invincible);
  // TODO:skill notify or notify state ?
  // I need to deceide which is good
  if (level < 3) {
  }
  return skill;
}
