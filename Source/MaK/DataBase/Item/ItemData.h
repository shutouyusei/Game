#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
  // Item ID
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
  FString itemData_;
};
