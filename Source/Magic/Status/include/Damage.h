#pragma once

#include "DamageStruct.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StatusComponent.h"

#include "Damage.generated.h"

UCLASS()
class UDamage : public UBlueprintFunctionLibrary {
  GENERATED_BODY()
public:
  UFUNCTION(BlueprintCallable, Category = "Damage")
  static float CalculateDamage(UStatusComponent *applyier,
                               UStatusComponent *target, FDamageStruct damage);
  UFUNCTION(BlueprintCallable, Category = "Damage")
  static void ApplyDamage(UStatusComponent *applyier, UStatusComponent *target,
                          FDamageStruct damage);
};
