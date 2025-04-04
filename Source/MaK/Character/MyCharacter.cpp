#include "MyCharacter.h"
#include "Attack/AttackCollision.h"
#include "Components/ChildActorComponent.h"
#include "EnhancedInputComponent.h"

AMyCharacter::AMyCharacter() {
  abilityManager_ = CreateDefaultSubobject<UAbilityManager>("AbilityManager");
  statusComponent_ =
      CreateDefaultSubobject<UStatusComponent>("StatusComponent");
  // 味方ポーンのタグはally
  this->Tags.Add("ally");
}

AMyCharacter::~AMyCharacter() {}

void AMyCharacter::BeginPlay() {
  Super::BeginPlay();
  // attach component
}

void AMyCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Super::EndPlay(EndPlayReason);
}

void AMyCharacter::SetupPlayerInputComponent(
    UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);

  if (EnhancedInputComponent != nullptr) {
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

void AMyCharacter::Attack() { abilityManager_->Execute(0); }

void AMyCharacter::Skill1() { abilityManager_->Execute(1); }
