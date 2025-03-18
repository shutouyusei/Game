#pragma once
#include "../AbilityModifier.h"

#include "InputAbilityModifier.generated.h"

class AMyCharacter;

UCLASS()
class UInputAbilityModifier final : public UAbilityModifier {
  GENERATED_BODY()
public:
  void AbilityMod(UAbilityManager *manager) override;

private:
  float CalcuateMoveRadians(AMyCharacter *character, FVector2D input);
};
