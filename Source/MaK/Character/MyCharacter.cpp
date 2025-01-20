#include "MyCharacter.h"
#include "Ability/NormalAttakck.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Components/ShapeComponent.h"
#include "EnhancedInputComponent.h"
#include "StatsComponent.h"

AMyCharacter::AMyCharacter() { StatsComponent statsComponent; }

AMyCharacter::~AMyCharacter() { delete normalAttack_; }

void AMyCharacter::SetNormalAttack(AAttackCollision *weapon) {
  StatsComponent statsComponent;
  StatsBase *stats = statsComponent.GetPlayerStats();
  normalAttack_ = NormalAttackFactory(weapon, stats)
                      .CreateAbility(GetMesh()->GetAnimInstance());
}

void AMyCharacter::SetupPlayerInputComponent(
    class UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);

  if (UEnhancedInputComponent *EnhancedInputComponent =
          Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
    // Normal Attack
    EnhancedInputComponent->BindAction(normalAttackAction_,
                                       ETriggerEvent::Started, this,
                                       &AMyCharacter::Attack);
  } else {
    UE_LOG(
        LogTemplateCharacter, Error,
        TEXT("'%s' Failed to find an Enhanced Input component! This template "
             "is built to use the Enhanced Input system. If you intend to use "
             "the legacy system, then you will need to update this C++ file."),
        *GetNameSafe(this));
  }
}

void AMyCharacter::Attack() { normalAttack_->DoAbility(this->GetTransform()); }
