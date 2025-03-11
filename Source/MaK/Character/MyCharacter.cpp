#include "MyCharacter.h"
#include "Attack/AttackCollision.h"
#include "Components/ChildActorComponent.h"
#include "EnhancedInputComponent.h"

AMyCharacter::AMyCharacter() {
  abilityManager_ = CreateDefaultSubobject<UAbilityManager>("AbilityManager");
  abilityManager_->RegisterComponent();
  skillActions_.SetNum(8);
  statusComponent_ = CreateDefaultSubobject<UStatusComponent>("StatusComponent");
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
  if (skillActions_.Num() != 8) {
    UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' skillActions_ size is not 8"), *GetNameSafe(this));
    return;
  }

  if (EnhancedInputComponent != nullptr) {
    // skill
    EnhancedInputComponent->BindAction(skillActions_[0], ETriggerEvent::Started, this, &AMyCharacter::Skill1);
    EnhancedInputComponent->BindAction(skillActions_[1], ETriggerEvent::Started, this, &AMyCharacter::Skill2);
    EnhancedInputComponent->BindAction(skillActions_[2], ETriggerEvent::Started, this, &AMyCharacter::Skill3);
    EnhancedInputComponent->BindAction(skillActions_[3], ETriggerEvent::Started, this, &AMyCharacter::Skill4);
    EnhancedInputComponent->BindAction(skillActions_[4], ETriggerEvent::Started, this, &AMyCharacter::Skill5);
    EnhancedInputComponent->BindAction(skillActions_[5], ETriggerEvent::Started, this, &AMyCharacter::Skill6);
    EnhancedInputComponent->BindAction(skillActions_[6], ETriggerEvent::Started, this, &AMyCharacter::Skill7);
    EnhancedInputComponent->BindAction(skillActions_[7], ETriggerEvent::Started, this, &AMyCharacter::Skill8);

    // Normal Attack
    EnhancedInputComponent->BindAction(normalAttackAction_, ETriggerEvent::Started, this, &AMyCharacter::NormalAttack);
  } else {
    UE_LOG(
        LogTemplateCharacter, Error,
        TEXT("'%s' Failed to find an Enhanced Input component! This template "
             "is built to use the Enhanced Input system. If you intend to use "
             "the legacy system, then you will need to update this C++ file."),
        *GetNameSafe(this));
  }
}

void AMyCharacter::Skill1() {
  abilityManager_->Execute(0);
}
void AMyCharacter::Skill2() {
  abilityManager_->Execute(1);
}
void AMyCharacter::Skill3() {
  abilityManager_->Execute(2);
}
void AMyCharacter::Skill4() {
  abilityManager_->Execute(3);
}
void AMyCharacter::Skill5() {
  abilityManager_->Execute(4);
}
void AMyCharacter::Skill6() {
  abilityManager_->Execute(5);
}
void AMyCharacter::Skill7() {
  abilityManager_->Execute(6);
}
void AMyCharacter::Skill8() {
  abilityManager_->Execute(7);
}
void AMyCharacter::NormalAttack() {
  abilityManager_->Execute(8);
}
