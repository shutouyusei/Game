#pragma once
#include "Components/ActorComponent.h"
#include "StatsBase.h"
#include "StatsStruct.h"

#include "StatsComponent.generated.h"

UCLASS()
class UStatsComponent : public UActorComponent {
  GENERATED_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  UStatsBase *Stats;
};
