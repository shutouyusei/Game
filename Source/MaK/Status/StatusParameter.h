#pragma once
#include "UObject/NoExportTypes.h"

#include "StatusParameter.generated.h"

UCLASS(EditInlineNew)
class UStatusParameter final : public UObject {
  GENERATED_BODY()
public:
  UStatusParameter();
  ~UStatusParameter();
  //
  UFUNCTION(BlueprintCallable, Category = "Status")
  float Get();
  //
public:
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Status")
  float defaultParameter_ = 0.0f;

  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Status")
  float ratio_ = 1.0f;

  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Status")
  float deviation_ = 0.0f;
};
