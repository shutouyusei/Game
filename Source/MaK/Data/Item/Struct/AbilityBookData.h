#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "AbilityBookData.generated.h"

USTRUCT(BlueprintType)
struct FAbilityBookData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName name;
};
