#include "MyCharacter.h"
#include "EnhancedInputComponent.h"
#include "Sword/Base/SwordAttackCombo.h"
#include "Sword/Skill/DodgeAttack1.h"

AMyCharacter::AMyCharacter() {}

AMyCharacter::~AMyCharacter() {}

void AMyCharacter::SetNormalAttack(AAttackCollision *weapon) {
  // attach component
  abilityManager_ = CreateDefaultSubobject<UAbilityManager>("AbilityManager");

  Ability *ability = new SwordAttackCombo(abilityManager_,
                                          GetMesh()->GetAnimInstance(), weapon);
  abilityManager_->AddAbility(ability);
  Ability *dodgeAbility =
      new DodgeAttack1(abilityManager_, GetMesh()->GetAnimInstance(), weapon);
  abilityManager_->AddAbility(dodgeAbility);
}
void AMyCharacter::BeginPlay() { Super::BeginPlay(); }

void AMyCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Super::EndPlay(EndPlayReason);
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
