#pragma once
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AttackCollision.generated.h"

UCLASS()
class AAttackCollision : public AActor {
  GENERATED_BODY()
public:
  AAttackCollision();
  ~AAttackCollision();

  void SetAbility(std::function<void(AActor *)> AbilityDelegate);
  void DeleteAbility();

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
  UStaticMeshComponent *collisionMesh;

protected:
  virtual void NotifyActorBeginOverlap(AActor *otherActor) override;

private:
  std::function<void(AActor *)> AbilityDelegate_;
};
