#pragma once
#include "CoreMinimal.h"
#include "Skill.h"
#include "SkillManager/SkillManager.h"
#include "UObject/NoExportTypes.h"

#include "SkillFactory.generated.h"
UCLASS(Blueprintable)
class USkillFactory : public UObject {
  GENERATED_BODY()
public:
  virtual USkill *Create(int32 level, USkillManager *manager);
  FSkillData get_skill_data(int32 level);

private:
  UPROPERTY(EditAnywhere)
  FSkillData level1_data;
  UPROPERTY(EditAnywhere)
  FSkillData level2_data;
  UPROPERTY(EditAnywhere)
  FSkillData level3_data;
};
