#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "OtherData.generated.h"

USTRUCT(BlueprintType)
struct FOtherData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName name;
  // TODO: Add Item Object
};
