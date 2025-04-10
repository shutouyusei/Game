#pragma once
#include "../../../SkillFactory.h"

#include "NormalSwordAttackFactory.generated.h"

UCLASS()
class UNormalSwordAttackFactory : public USkillFactory {
  GENERATED_BODY()
public:
  USkill *Create(USkillManager *manager) override;

private:
  UPROPERTY(EditAnywhere)
  TObjectPtr<UAnimMontage> montage_;
};
