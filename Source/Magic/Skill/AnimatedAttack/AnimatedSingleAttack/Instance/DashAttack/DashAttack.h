#pragma once

#include "../../AnimatedSingleAttackSkill.h"

#include "DashAttack.generated.h"

UCLASS()
class UDashAttack final : public UAnimatedSingleAttackSkill {
  GENERATED_BODY()
public:
  ~UDashAttack();
  void Activate() override;
  void OnAttack(ACharacter *target) override;
};
