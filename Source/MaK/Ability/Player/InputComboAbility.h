#pragma once
#include "../Ability.h"
#include "Math/Vector2D.h"

#include "InputComboAbility.generated.h"

class AMyCharacter;

UCLASS(Blueprintable)
class UInputComboAbility : public UAbility {
  GENERATED_BODY()
public:
  virtual void DoAbility() override;
  virtual void EndAbility() override;

protected:
  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
  float CalcuateMoveRadians(AMyCharacter *character, FVector2D input);

protected:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TSubclassOf<UAbility> InputAbility_;

private:
  UPROPERTY()
  UAbility *Ability_;
};
