#pragma once

#include "CoreMinimal.h"

#include "Belonging.generated.h"

USTRUCT(BlueprintType)
struct FBelonging {
  GENERATED_USTRUCT_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int num;
};

class Belongings {
public:
  // Set
  // setはアイテムの増減のみで許される
  void IncreaseBelongings(int id, int num);
  void DecreaseBelongings(int id, int num);
  // Get
  const TArray<FBelonging> GetBelongingInstances(){ return belongings; }

private:
  void AddBelongings(int id, int num);
  void RemoveBelongings(int index);

private:
  TArray<FBelonging> belongings;
};
