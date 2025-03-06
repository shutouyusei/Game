#pragma once
#include "AbilityManager.h"
#include "MaKCharacter.h"
#include "StatusComponent.h"

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

  void Skill1();
  void Skill2();
  void Skill3();
  void Skill4();
  void Skill5();
  void Skill6();
  void Skill7();
  void Skill8();
  void NormalAttack();
protected:
  virtual void
  SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) override;
  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
  UAbilityManager *abilityManager_;

  UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Status")
  UStatusComponent *statusComponent_;

private:
  UPROPERTY(EditAnywhere, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *normalAttackAction_;

  UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivat = "true"))
  TArray<UInputAction *> skillActions_;
};
