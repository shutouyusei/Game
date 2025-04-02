#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "SkillExecutionManager.generated.h"

class USkill;

UENUM(BlueprintType)
enum class ESkillFlag : uint8 {
  None = 0,
  CanNextAbility = 1,
  CanInput = 2,
  Playing = 3,
};

UCLASS()
class USkillExecutionManager : public UObject {
  GENERATED_BODY()
public:
  void ExecuteSkill(USkill *skill);
  void FinishSkill();
  // アビリティからの通知
  void SetSkillFlag(ESkillFlag flag);

  USkill *get_current_skill(){return current_skill_;};
  // TObjectPtr<UStatus> status;
private:
  inline void ActivateSkill(USkill *skill);

public:
  UPROPERTY()
  bool can_jump_ = true;

private:
  UPROPERTY()
  TObjectPtr<USkill> current_skill_;
  UPROPERTY()
  ESkillFlag ability_flag_ = ESkillFlag::None;
  UPROPERTY()
  TObjectPtr<USkill> next_skill_;
};
