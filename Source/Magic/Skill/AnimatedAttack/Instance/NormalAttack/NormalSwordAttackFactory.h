#pragma once
#include "../AnimatedAttackSkillFactory.h"

#include "NormalSwordAttackFactory.generated.h"

class USkillNotify;

UCLASS()
class UNormalSwordAttackFactory : public UAnimatedAttackSkillFactory {
  GENERATED_BODY()
protected:
  USkill *CreateSkill(int32 level, USkillManager *manager) override;
  USkillNotify *get_skill_notify(UAnimatedAttack *attack_module);

private:
  UPROPERTY(EditAnywhere)
  TArray<UAnimMontage *> montages_on_ground_;
  UPROPERTY(EditAnywhere)
  TArray<UAnimMontage *> montages_in_air_;
};
