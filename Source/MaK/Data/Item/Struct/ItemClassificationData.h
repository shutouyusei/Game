#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "ItemClassificationData.generated.h"

UENUM(BlueprintType)
enum class EItemClassificationDataType : uint8 {
  Useable,
  Material,
  AbilityBook,
  Important,
};

USTRUCT(BlueprintType)
struct FItemClassificationData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  EItemClassificationDataType type;
};
