#pragma once
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "DamageStruct.h"
#include "GameFramework/Actor.h"

#include "AttackCollision.generated.h"

UCLASS()
class AAttackCollision : public AActor {
  GENERATED_BODY()
public:
  AAttackCollision();
  ~AAttackCollision();

  void StartAttack(AActor *applyier, FDamageStruct damage);
  void EndAttack();

private:
  void NotifyActorBeginOverlap(AActor *otherActor) override;

private:
  std::function<void(AActor *)> ability_delegate_;
  UPROPERTY(VisibleAnywhere, Category = "Collision")
  TObjectPtr<UStaticMeshComponent> collisionMesh;
};
