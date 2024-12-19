#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FetchedData.generated.h"

USTRUCT(BlueprintType)
struct FFetchedData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
  FString name;
  FString item;
};
