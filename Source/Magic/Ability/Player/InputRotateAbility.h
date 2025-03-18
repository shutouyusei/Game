#pragma once
#include "../Ability.h"

#include "InputRotateAbility.generated.h"

class AMyCharacter;

UCLASS(Blueprintable)
class UInputRotateAbility : public UAbility {
  GENERATED_BODY()
public:
  void DoAbility() override;
  void EndAbility() override;
  //
  void BeginPlay(TObjectPtr<UAbilityManager> manager) override;
  void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
  float CalcuateMoveRadians(AMyCharacter *character, FVector2D input);

protected:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TSubclassOf<UAbility> input_ability_;

private:
  UPROPERTY()
  TObjectPtr<UAbility> ability_;
};
