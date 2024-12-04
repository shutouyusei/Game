#pragma once

#include "../../../Stats/CharacterStats.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "AccessoryData.generated.h"

USTRUCT(BlueprintType)
struct FAccessoryData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName name;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FCharacterStats stats;
};
