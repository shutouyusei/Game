#pragma once
#include "../../../Skill.h"

#include "NormalSwordAttack.generated.h"

class ACharacter;
class UAnimatedAttack;

UCLASS()
class UNormalSwordAttack final : public USkill {
  GENERATED_BODY()
public:
  void Activate() override;

private:
  void AttackinAir(int32 combo);
  void AttackonGround(int32 combo);

public:
  UPROPERTY()
  TArray<UAnimatedAttack *> attack_on_ground_modules_;
  UPROPERTY()
  TArray<UAnimatedAttack *> attack_in_air_modules_;

private:
  UPROPERTY()
  int32 combo_ = 0;
};
