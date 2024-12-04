#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "MaterialData.generated.h"

USTRUCT(BlueprintType)
struct FMaterialData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName name;
};
