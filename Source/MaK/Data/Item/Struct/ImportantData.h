#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "ImportantData.generated.h"

USTRUCT(BlueprintType)
struct FImportantData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName name;
};
