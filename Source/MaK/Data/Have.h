#pragma once

#include "CoreMinimal.h"

#include "Have.generated.h"

USTRUCT(BlueprintType)
struct FHave {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int num;
};
