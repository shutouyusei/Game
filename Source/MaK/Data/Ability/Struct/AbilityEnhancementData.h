#pragma once

#include "../../Have.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "AbilityEnhancementData.generated.h"

USTRUCT(BlueprintType)
struct FAbilityEnhancementData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TArray<FHave> MaterialList;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int id;
};
