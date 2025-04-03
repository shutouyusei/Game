#pragma once
#include "../../Skill.h"
#include "../AnimatedAttack.h"
#include "AnimatedSingleAttackSkillFactory.h"

#include "AnimatedSingleAttackSkill.generated.h"

UCLASS(Blueprintable)
class UAnimatedSingleAttackSkill : public USkill {
  GENERATED_BODY()
public:
  virtual ~UAnimatedSingleAttackSkill();

public:
  UPROPERTY()
  TObjectPtr<UAnimatedAttack> attack_module_;
};
