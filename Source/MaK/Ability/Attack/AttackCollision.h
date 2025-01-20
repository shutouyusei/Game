#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <functional>

#include "AttackCollision.generated.h"

class AttackAbility;

UCLASS()
class AAttackCollision : public AActor {
  GENERATED_BODY()

public:
  void SetAbility(std::function<void(AActor *)> AbilityDelegate);
  void DeleteAbility();
  virtual void NotifyActorBeginOverlap(AActor *otherActor) override;

private:
  bool bCanDealDamage = false;
  std::function<void(AActor *)> AbilityDelegate_;
};
