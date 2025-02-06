#pragma once
#include "AbilityManager.h"
#include "MaKCharacter.h"
#include "MyCharacter.generated.h"

class Ability;
class UAnimMontage;
class UInputComponent;

UCLASS()
class AMyCharacter : public AMaKCharacter {
  GENERATED_BODY()
public:
  AMyCharacter();
  ~AMyCharacter();

private:
  // Ability Function
  void Attack();
  void Skill1();

public:
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
  UAbilityManager *abilityManager_;

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
};
