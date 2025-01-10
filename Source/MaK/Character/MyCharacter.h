#pragma once
#include "MaKCharacter.h"
#include "MyCharacter.generated.h"

class Ability;
class UAnimMontage;

UCLASS()
class AMyCharacter : public AMaKCharacter {
  GENERATED_BODY()
public:
  AMyCharacter();
  ~AMyCharacter();

private:
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;
  // Ability Function
  void Attack();

private:
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *normalAttackAction_;
  Ability *normalAttack_;
};
