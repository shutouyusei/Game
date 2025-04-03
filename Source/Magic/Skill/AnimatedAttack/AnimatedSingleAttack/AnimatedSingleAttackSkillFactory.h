#pragma once
#include "../../SkillFactory.h"

#include "AnimatedSingleAttackSkillFactory.generated.h"

class UAnimatedAttack;
class UAnimMontage;
class UAnimatedSingleAttackSkill;

UCLASS(Blueprintable)
class UAnimatedSingleAttackSkillFactory : public USkillFactory {
  GENERATED_BODY()
public:
  USkill *Create(USkillManager *manager) override;

private:
  UAnimatedAttack *CreateAnimatedAttack(USkillManager *manager);
  void SetNSAnimatedAttack(UAnimatedAttack *attack_module);

private:
  UPROPERTY(EditAnywhere)
  TSubclassOf<UAnimMontage> montage_class_;
  UPROPERTY(EditAnywhere)
  TSubclassOf<UAnimatedSingleAttackSkill> skill_class_;
  UPROPERTY(EditAnywhere)
  FName socket_name_;
};
