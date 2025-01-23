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
  virtual void
  SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) override;
  // Ability Function
  void Attack();
  void Skill1();

private:
  UPROPERTY(EditAnywhere, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *normalAttackAction_;

  UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivat = "true"))
  UInputAction *skill1Action_;

  AbilityManager *abilityManager_;
  TArray<Ability *> abilities_;
};
