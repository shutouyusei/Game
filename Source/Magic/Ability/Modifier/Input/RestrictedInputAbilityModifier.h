#pragma once
#include "../AbilityModifier.h"

#include "RestrictedInputAbilityModifier.generated.h"
class AMyCharacter;

UCLASS(Blueprintable, BlueprintType)
class URestrictedInputAbilityModifier final : public UAbilityModifier {
  GENERATED_BODY()
public:
  void AbilityMod(UAbilityManager *manager) override;

private:
  float CalcuateMoveRadians(AMyCharacter *character, FVector2D input);
};
