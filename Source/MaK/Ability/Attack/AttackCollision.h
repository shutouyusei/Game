#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AttackCollision.generated.h"

class UStaticMeshComponent;

UCLASS()
class AAttackCollision : public AActor {
  GENERATED_BODY()
  AAttackCollision();
  ~AAttackCollision();

public:
  void SetAbility(std::function<void(AActor *)> AbilityDelegate);
  void DeleteAbility();

public:
  UPROPERTY(EditAnywhere)
  UStaticMeshComponent *CollisionMesh;

protected:
  virtual void NotifyActorBeginOverlap(AActor *otherActor) override;

private:
  bool bCanDealDamage_ = false;
  std::function<void(AActor *)> AbilityDelegate_;
};
