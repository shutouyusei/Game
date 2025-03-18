#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "MaterialData.generated.h"

USTRUCT(BlueprintType)
struct FMaterialData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()

  // Material ID
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterialData")
  FString itemName_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterialData")
  UTexture2D *itemIcon_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterialData")
  FString itemDescription_;
};
