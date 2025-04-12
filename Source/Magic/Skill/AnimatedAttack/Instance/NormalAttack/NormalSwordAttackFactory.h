#pragma once
#include "../../../SkillFactory.h"

#include "NormalSwordAttackFactory.generated.h"

UCLASS()
class UNormalSwordAttackFactory : public USkillFactory {
  GENERATED_BODY()
public:
  USkill *Create(int32 level, USkillManager *manager) override;
};
