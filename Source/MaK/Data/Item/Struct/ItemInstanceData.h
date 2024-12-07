#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "ItemInstanceData.generated.h"

USTRUCT(BlueprintType)
struct FItemInstanceData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString itemPath;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName name;
};
