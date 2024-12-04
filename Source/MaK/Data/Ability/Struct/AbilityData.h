#pragma once

#include "../Ability.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "AbilityData.generated.h"

USTRUCT(BlueprintType)
struct FAbilityData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName name;
  // TODO なんか選べない

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TSubclassOf<UAbility> abilityClass;
};
