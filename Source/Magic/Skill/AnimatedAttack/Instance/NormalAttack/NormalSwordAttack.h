#pragma once
#include "../../../Skill.h"

#include "NormalSwordAttack.generated.h"

class ACharacter;
class UAnimatedAttack;
class UCharacterMovementComponent;

UCLASS()
class UNormalSwordAttack final : public USkill {
  GENERATED_BODY()
public:
  void Activate() override;
  UFUNCTION()
  void EndCombo();
  UFUNCTION()
  void Jump(ACharacter *character);
  UFUNCTION()
  void Float(ACharacter *character);

private:
  void AttackinAir(int32 combo);
  void AttackonGround(int32 combo);
  bool get_in_air() const;

public:
  UPROPERTY()
  TArray<UAnimatedAttack *> attack_on_ground_modules_;
  UPROPERTY()
  TArray<UAnimatedAttack *> attack_in_air_modules_;
  UPROPERTY()
  UCharacterMovementComponent *movement_component_;

private:
  UPROPERTY()
  int32 combo_ = 0;
};
