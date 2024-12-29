#pragma once
#include "CoreMinimal.h"

#include "StatsStruct.generated.h"
/**
 *
 */
USTRUCT(BlueprintType)
struct FStatsStruct {
  GENERATED_USTRUCT_BODY()
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float HP = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float MP = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float AD = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float AP = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float AR = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float MR = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float FireRes = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float IceRes = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float DarkRes = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float ElecRes = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
  float HolyRes = 0.0;
};
