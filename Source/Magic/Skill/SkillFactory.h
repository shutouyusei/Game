#pragma once
#include "CoreMinimal.h"
#include "Skill.h"
#include "UObject/NoExportTypes.h"

#include "SkillFactory.generated.h"

UCLASS(Blueprintable)
class USkillFactory : public UObject {
  GENERATED_BODY()
public:
  virtual USkill *Create();
};
