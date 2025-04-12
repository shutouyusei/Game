#pragma once

#include "CoreMinimal.h"
#include "DamageInfo.generated.h"

USTRUCT(BlueprintType)
struct FDamageInfo {
  GENERATED_USTRUCT_BODY()
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
  float damage = 0.0f;
};
