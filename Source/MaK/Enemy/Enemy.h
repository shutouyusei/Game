#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StatsStruct.h"

#include "Enemy.generated.h"

UCLASS()
class AEnemy : public ACharacter {
  GENERATED_BODY()
public:
  AEnemy();
  ~AEnemy();

protected:
  void BeginPlay() override;

private:
  UPROPERTY(EditAnywhere, Category = "Stats")
  FStatsStruct stats_;
};
