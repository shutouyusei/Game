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
  void increaseBelongings(int id, int num);
  void decreaseBelongings(int id, int num);
  // Get
  const FBelonging getBelonging(int id) const;

private:
  void addBelongings(int id, int num);
  void removeBelongings(int index);

private:
  TArray<FBelonging> belongings;
};
