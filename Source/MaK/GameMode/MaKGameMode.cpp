// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaKGameMode.h"
#include "../Character/MaKCharacter.h"
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
  character =
      Cast<AMaKCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
  if (character == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("Character is null"));
  }

  // UI
  SetItemUI();
  if (wbItem != nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("wbItem is not null"));
    wbItem->AddToViewport();
  }
}

void AMaKGameMode::SetItemUI() {
  if (wbItemClass == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("wbItemClass is null"));
    return;
  }
  UWBItem *wbItemInstance = CreateWidget<UWBItem>(GetWorld(), wbItemClass);
  if(wbItemInstance == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("wbItemInstance is null"));
    return;
  }
  wbItemInstance->SetCharacter(character);
}
