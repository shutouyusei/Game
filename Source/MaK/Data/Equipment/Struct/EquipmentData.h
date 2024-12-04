#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "EquipmentData.generated.h"

UENUM(BlueprintType)
enum class EEquipmentDataType : uint8 {
  Weapon,
  Head,
  UpperArmor,
  BottomArmor,
  Accessory,
};

USTRUCT(BlueprintType)
struct FEquipmentData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  EEquipmentDataType type;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int id;
};
