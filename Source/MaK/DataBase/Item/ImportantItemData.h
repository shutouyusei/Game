#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "ImportantItemData.generated.h"

USTRUCT(BlueprintType)
struct FImportantItemDataData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()

  // ImportantItemData ID
  UPROPERTY(EditAnywhere, BlueprintReadWrite,
            Category = "ImportantItemDataData")
  FString itemName_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite,
            Category = "ImportantItemDataData")
  UTexture2D *itemIcon_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite,
            Category = "ImportantItemDataData")
  FString itemDescription_;
};
