#pragma once
#include "../StatsParameter.h"
#include "UObject/NoExportTypes.h"

#include "StatsBase.generated.h"

UCLASS()
class UStatsBase : public UObject {
  GENERATED_BODY()
public:
  UStatsBase();
  virtual ~UStatsBase();
  UFUNCTION(BlueprintCallable, Category = "Stats")
  float GetHP();
  UFUNCTION(BlueprintCallable, Category = "Stats")
  void Damage(float damage);
  UFUNCTION(BlueprintCallable, Category = "Stats")
  void Heal(float heal);
  //
  UFUNCTION(BlueprintCallable, Category = "Stats")
  float GetMP();
  UFUNCTION(BlueprintCallable, Category = "Stats")
  bool UseMP(float mp);
  UFUNCTION(BlueprintCallable, Category = "Stats")
  void RestoreMP(float mp);

public:
  //
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats")
  UStatsParameter *HP_;
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats")
  UStatsParameter *MP_;
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats")
  UStatsParameter *AD_;
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats")
  UStatsParameter *AP_;
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats")
  UStatsParameter *AR_;
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats")
  UStatsParameter *MR_;

private:
  float currentHP_;
  float currentMP_;
};
