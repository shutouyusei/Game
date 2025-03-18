#pragma once
#include "CoreMinimal.h"

#include "StatusStruct.generated.h"
/**
 *
 */
USTRUCT(BlueprintType)
struct FStatusStruct {
  GENERATED_USTRUCT_BODY()
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float HP = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float MP = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float AD = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float AP = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float AR = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float MR = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float FireRes = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float IceRes = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float DarkRes = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float ElecRes = 0.0;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
  float HolyRes = 0.0;
};
