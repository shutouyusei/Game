#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "ItemData.generated.h"

UENUM(BlueprintType)
enum class EItemDataType : uint8 {
  Useable,
  Material,
  AbilityBook,
  Important,
};

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  EItemDataType type;
};
