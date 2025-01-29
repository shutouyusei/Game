#pragma once

#include "CoreMinimal.h"
#include "DamageStruct.generated.h"

UENUM(BlueprintType)
enum class EDamageType : uint8 {
  Physical,
  Magical,
};

UENUM(BlueprintType)
enum class EDamageElementType : uint8 {
  Fire,
  Ice,
  Dark,
  Elec,
  Holy,
  None,
};

USTRUCT(BlueprintType)
struct FDamageStruct {
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
  float power = 0.0;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
  EDamageType damageType = EDamageType::Physical;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
  EDamageElementType damageElement = EDamageElementType::None;
};
