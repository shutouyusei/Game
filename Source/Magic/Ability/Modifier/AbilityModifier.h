#pragma once
#include "CoreMinimal.h"
#include "Manager/AbilityManager.h"
#include "UObject/NoExportTypes.h"

#include "AbilityModifier.generated.h"

UCLASS(BlueprintType, DefaultToInstanced)
class UAbilityModifier : public UObject {
  GENERATED_BODY()
public:
  virtual void AbilityMod(UAbilityManager *manager);
};
