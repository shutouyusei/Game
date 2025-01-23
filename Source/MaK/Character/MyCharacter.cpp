#include "MyCharacter.h"
#include "AbilityManager.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Attack/AttackAbilityFactory.h"
#include "Components/ShapeComponent.h"
#include "EnhancedInputComponent.h"
#include "StatsComponent.h"

AMyCharacter::AMyCharacter() { StatsComponent statsComponent; }

AMyCharacter::~AMyCharacter() { delete abilityManager_; }

void AMyCharacter::SetNormalAttack(AAttackCollision *weapon) {
  StatsComponent statsComponent;
  StatsBase *stats = statsComponent.GetPlayerStats();

  UAnimMontage *animMontage = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack1.AM_Attack1"));
  FDamageStruct damage = {10.0, EDamageType::Physical,
                          EDamageElementType::None};

  {
    AttackFactory attackFactory(animMontage, damage, this, weapon);
    abilities_.Add(attackFactory.CreateAbility(GetMesh()->GetAnimInstance()));
  }

  animMontage = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_DashAttack1.AM_DashAttack1"));
  damage = {20.0, EDamageType::Physical, EDamageElementType::None};
  {
    AttackFactory attackFactory(animMontage, damage, this, weapon);
    abilities_.Add(attackFactory.CreateAbility(GetMesh()->GetAnimInstance()));
  }

  abilityManager_ = new AbilityManager(abilities_);
}

void AMyCharacter::SetupPlayerInputComponent(
    UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);

  if (UEnhancedInputComponent *EnhancedInputComponent =
          Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
    // Normal Attack
    EnhancedInputComponent->BindAction(normalAttackAction_,
                                       ETriggerEvent::Started, this,
                                       &AMyCharacter::Attack);
    EnhancedInputComponent->BindAction(skill1Action_, ETriggerEvent::Started,
                                       this, &AMyCharacter::Skill1);
  } else {
    UE_LOG(
        LogTemplateCharacter, Error,
        TEXT("'%s' Failed to find an Enhanced Input component! This template "
             "is built to use the Enhanced Input system. If you intend to use "
             "the legacy system, then you will need to update this C++ file."),
        *GetNameSafe(this));
  }
}

void AMyCharacter::Attack() { abilityManager_->ExecuteAbility(0); }

void AMyCharacter::Skill1() { abilityManager_->ExecuteAbility(1); }
