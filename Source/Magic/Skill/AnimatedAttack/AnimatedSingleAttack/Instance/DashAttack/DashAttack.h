#pragma once

#include "../../AnimatedSingleAttackSkill.h"

#include "DashAttack.generated.h"

class ACharacter;

UCLASS()
class UDashAttack final : public UAnimatedSingleAttackSkill {
  GENERATED_BODY()
public:
  void SetSkillData(FSkillData data) override;
  void Activate() override;

private:
  void OnMotageEnded(UAnimMontage *montage, bool interrupted);

private:
  UPROPERTY()
  TObjectPtr<ACharacter> owner_ = nullptr;
};
