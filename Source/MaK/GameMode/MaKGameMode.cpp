// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaKGameMode.h"
#include "../UI/UIManager.h"
#include "../Character/MaKCharacter.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AMaKGameMode::AMaKGameMode() {
  // set default pawn class to our Blueprinted character
  static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
      TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
  if (PlayerPawnBPClass.Class != NULL) {
    DefaultPawnClass = PlayerPawnBPClass.Class;
  }
}

void AMaKGameMode::BeginPlay() {
  Super::BeginPlay();
  // Character
  character_ =
      Cast<AMaKCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
  if (character_ == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("Character is null"));
  }

  uiManager_ = new UIManager(character_);
  // UI
  uiManager_->SetItemUI();
}

