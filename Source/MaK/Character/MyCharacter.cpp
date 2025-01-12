#include "MyCharacter.h"
#include "Ability/NormalAttakck.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "EnhancedInputComponent.h"

AMyCharacter::AMyCharacter() {
}
void AMyCharacter::BeginPlay() {
  Super::BeginPlay();
  normalAttack_ =
      NormalAttackFactory().CreateAbility(GetMesh()->GetAnimInstance());
}

AMyCharacter::~AMyCharacter() { delete normalAttack_; }

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
