#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "ItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()

  // Item ID
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
  FString itemName_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
  UTexture2D *itemIcon_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
  FString itemDescription_;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
  FString itemPath_;
};
