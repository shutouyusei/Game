#pragma once
#include "../MyController.h"
#include "EnemyBehaviorState.h"

#include "EnemyContoroller.generated.h"

struct FBlackboardKeySelector;

UCLASS()
class AEnemyContoroller : public AMyController {
  GENERATED_BODY()
public:
  AEnemyContoroller();

  UFUNCTION(BlueprintCallable)
  void SwitchBehaiviorState(EEnemyBehaiviorState NewState);

protected:
  UPROPERTY(EditAnywhere, Category = "State")
  EEnemyBehaiviorState BehaiviorState_;
};
