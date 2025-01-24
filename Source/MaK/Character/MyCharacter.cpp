#include "MyCharacter.h"
#include "AbilityManager.h"
#include "EnhancedInputComponent.h"
#include "Sword/Base/SwordAttack1.h"
#include "Sword/Skill/DodgeAttack1.h"

AMyCharacter::AMyCharacter() {}

AMyCharacter::~AMyCharacter() {}

void AMyCharacter::SetNormalAttack(AAttackCollision *weapon) {
  abilityManager_ = new AbilityManager();
  Ability *ability =
      new SwordAttack1(this, GetMesh()->GetAnimInstance(), weapon);
  abilityManager_->AddAbility(ability);
  Ability *dodgeAbility =
      new DodgeAttack1(this, GetMesh()->GetAnimInstance(), weapon);
  abilityManager_->AddAbility(dodgeAbility);
}
void AMyCharacter::BeginPlay() { Super::BeginPlay(); }

void AMyCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Super::EndPlay(EndPlayReason);
  delete abilityManager_;
  abilityManager_ = nullptr;
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
