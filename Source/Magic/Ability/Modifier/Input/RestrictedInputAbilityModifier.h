#pragma once
#include "../AbilityModifier.h"

#include "RestrictedInputAbilityModifier.generated.h"
class AMyCharacter;

UCLASS()
class URestrictedInputAbilityModifier  final : public UAbilityModifier {
  GENERATED_BODY()
public:
  void AbilityMod(UAbilityManager *manager);
private:
  float CalcuateMoveRadians(AMyCharacter *character, FVector2D input);
};
