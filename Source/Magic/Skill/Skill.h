#pragma once
#include "CoreMinimal.h"
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
  void Deactivate();
  // BeginPlay
  virtual void BeginPlay() {};
  // Tick
  virtual void Tick(float DeltaTime) {};
  // End
  virtual void EndPlay() {};
  // アビリティ発動条件の記述
  virtual bool can_activate();

public:
  UPROPERTY()
  TObjectPtr<USkillManager> manager_;
};
