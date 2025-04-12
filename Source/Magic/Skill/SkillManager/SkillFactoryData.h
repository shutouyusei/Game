#pragma once
#include "CoreMinimal.h"

#include "SkillFactoryData.generated.h"
class USkillFactory;

USTRUCT(BlueprintType)
struct FSkillFactoryData {
  GENERATED_USTRUCT_BODY()
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  int32 level = 1;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
  TSubclassOf<USkillFactory> factory_class;
};
