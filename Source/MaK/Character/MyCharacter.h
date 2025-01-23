#pragma once
#include "Ability/NormalAttakck.h"
#include "MaKCharacter.h"
#include "MyCharacter.generated.h"

class Ability;
class UAnimMontage;
class UShapeComponent;
class AbilityManager;

UCLASS()
class AMyCharacter : public AMaKCharacter {
  GENERATED_BODY()
public:
  AMyCharacter();
  ~AMyCharacter();

  UFUNCTION(BlueprintCallable, Category = "Ability")
  void SetNormalAttack(AAttackCollision *weapon);

private:
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;
  // Ability Function
  void Attack();

private:
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *normalAttackAction_;
  AbilityManager *abilityManager_;
  TArray<Ability *> abilities_;
};
