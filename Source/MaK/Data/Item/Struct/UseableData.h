#pragma once

#include "../Item.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "UseableData.generated.h"

USTRUCT(BlueprintType)
struct FUseableData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TSubclassOf<UItem> item;
};
