#pragma once
#include "MaKCharacter.h"
#include "MyCharacter.generated.h"

class Ability;
class UAnimMontage;
class UShapeComponent;
class AbilityManager;
class UInputComponent;

UCLASS()
class AMyCharacter : public AMaKCharacter {
  GENERATED_BODY()
public:
  AMyCharacter();
  ~AMyCharacter();

  UFUNCTION(BlueprintCallable, Category = "Ability")
  void SetNormalAttack(AAttackCollision *weapon);

private:
  // Ability Function
  void Attack();
  void Skill1();

protected:
  virtual void
  SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) override;
  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
  UPROPERTY(EditAnywhere, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *normalAttackAction_;

  UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivat = "true"))
  UInputAction *skill1Action_;

  AbilityManager *abilityManager_;
};
