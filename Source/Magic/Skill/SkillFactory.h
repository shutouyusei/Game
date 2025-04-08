#pragma once
#include "CoreMinimal.h"
#include "Skill.h"
#include "SkillData.h"
#include "UObject/NoExportTypes.h"

#include "SkillFactory.generated.h"

UCLASS(Blueprintable)
class USkillFactory : public UObject {
  GENERATED_BODY()
public:
  virtual USkill *Create(USkillManager *manager);

protected:
  UPROPERTY(EditAnywhere)
  FSkillData data_;
};
