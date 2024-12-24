#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"

#include "AbilityBookData.generated.h"
USTRUCT(BlueprintType)
struct FAbilityBookData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()

  // AbilityBook ID
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityBookData")
  FString itemName_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityBookData")
  UTexture2D *itemIcon_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityBookData")
  FString itemDescription_;
};
