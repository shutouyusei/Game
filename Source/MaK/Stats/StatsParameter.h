#pragma once
#include "UObject/NoExportTypes.h"

#include "StatsParameter.generated.h"

UCLASS()
class UStatsParameter : public UObject {
  GENERATED_BODY()
public:
  UStatsParameter();
  virtual ~UStatsParameter() = default;
  //
  UFUNCTION(BlueprintCallable, Category = "Stats")
  float Get();
  //
public:
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats")
  float defaultParameter_ = 0.0f;

  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats")
  float ratio_ = 1.0f;

  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats")
  float deviation_ = 0.0f;
};
