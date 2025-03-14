#pragma once
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AttackCollision.generated.h"

DECLARE_DELEGATE_OneParam(FAbilityDelegate,AActor*);

UCLASS()
class AAttackCollision : public AActor {
  GENERATED_BODY()
public:
  AAttackCollision();
  ~AAttackCollision();

  void DeleteAbility();
public:
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
  UStaticMeshComponent *collisionMesh;
  //
  FAbilityDelegate ability_delegate_;

private:
  void NotifyActorBeginOverlap(AActor *otherActor) override;
};
