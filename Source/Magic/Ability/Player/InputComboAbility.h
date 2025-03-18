#pragma once
#include "../Ability.h"

#include "InputComboAbility.generated.h"

class AMyCharacter;

UCLASS(Blueprintable)
class UInputComboAbility : public UAbility {
  GENERATED_BODY()
public:
  void DoAbility() override;
  void EndAbility() override;

  void BeginPlay(TObjectPtr<UAbilityManager> manager) override;
  void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
  float CalcuateMoveRadians(AMyCharacter *character, FVector2D input);

private:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TSubclassOf<UAbility> input_ability_;

  UPROPERTY()
  TObjectPtr<UAbility> ability_;
};
