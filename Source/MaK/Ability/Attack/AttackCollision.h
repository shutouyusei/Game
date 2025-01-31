#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AttackCollision.generated.h"

UCLASS()
class AAttackCollision : public AActor {
  GENERATED_BODY()

public:
  void SetAbility(std::function<void(AActor *)> AbilityDelegate);
  void DeleteAbility();

protected:
  virtual void NotifyActorBeginOverlap(AActor *otherActor) override;

private:
  bool bCanDealDamage_ = false;
  std::function<void(AActor *)> AbilityDelegate_;
};
