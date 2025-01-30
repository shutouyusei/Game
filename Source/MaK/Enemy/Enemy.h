#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StatsStruct.h"
#include "Perception/AIPerceptionComponent.h"

#include "Enemy.generated.h"

class UAIPerceptionComponent;

UCLASS()
class AEnemy : public ACharacter {
  GENERATED_BODY()
public:
  AEnemy();
  ~AEnemy();

protected:
  void BeginPlay() override;

public:
  UPROPERTY(VisibleAnywhere,Category="Perception")
  UAIPerceptionComponent *PerceptionComponent;
private:
  UPROPERTY(EditAnywhere, Category = "Stats")
  FStatsStruct stats_;
};
