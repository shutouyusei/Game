#pragma once
#include "CoreMinimal.h"
#include "Perception/AIPerceptionTypes.h"

#include "AIMemory.generated.h"

USTRUCT(BlueprintType)
struct FAIMemory {
  GENERATED_USTRUCT_BODY()
public:
  float time;
  FAIStimulus Stimulus;
};
