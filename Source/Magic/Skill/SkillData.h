#pragma once

#include "CoreMinimal.h"
#include "SkillData.generated.h"

USTRUCT(BlueprintType)
struct FSkillData {
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  int32 level = 1;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  float cooldown = 0.0f;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  float resource = 0.0f;
};
