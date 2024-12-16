// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaKGameMode.h"
#include "../GameInstance/MyGameInstance.h"
#include "../UI/UIManager.h"
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
  // UI
  uiManager_ = new UIManager();
  // item component
}
