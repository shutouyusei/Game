#pragma once
#include "CoreMinimal.h"
#include "SkillData.h"
#include "SkillManager/SkillManager.h"
#include "UObject/NoExportTypes.h"

#include "Skill.generated.h"

UCLASS(Blueprintable)
class USkill : public UObject {
  GENERATED_BODY()
public:
  virtual ~USkill();
  // スキルの実行
  virtual void Activate() {};
  // Tick
  virtual void Tick(float DeltaTime) {};
  // アビリティ発動条件の記述
  virtual bool can_activate();

public:
  UPROPERTY()
  TObjectPtr<USkillManager> manager_;
  UPROPERTY()
  int32 level_;
  UPROPERTY()
  FSkillData skill_data_;
};
