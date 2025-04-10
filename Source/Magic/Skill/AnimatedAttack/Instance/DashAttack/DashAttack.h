#pragma once
#include "../../../Skill.h"

#include "DashAttack.generated.h"

class ACharacter;
class UAnimatedAttack;

UCLASS()
class UDashAttack final : public USkill {
  GENERATED_BODY()
public:
  void Activate() override;
  void OnMotageEnded(UAnimMontage *montage, bool interrupted);

public:
  UPROPERTY()
  TObjectPtr<UAnimatedAttack> attack_module_ = nullptr;
  UPROPERTY()
  TObjectPtr<ACharacter> owner_ = nullptr;
};
