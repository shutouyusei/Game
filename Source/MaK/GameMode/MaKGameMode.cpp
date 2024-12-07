// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaKGameMode.h"
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
  character =
      Cast<AMaKCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
  if (character == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("Character is null"));
  }

  // UI
  SetItemUI();
}

#define ITEM_UI_PATH "/Game/UI/WBItem.WBItem_C"

void AMaKGameMode::SetItemUI() {
  FString path = TEXT(ITEM_UI_PATH);
  TSubclassOf<UUserWidget> widgetClass =
      TSoftClassPtr<UUserWidget>(FSoftObjectPath(*path)).LoadSynchronous();
  APlayerController *playerController =
      UGameplayStatics::GetPlayerController(GetWorld(), 0);
  if (widgetClass && playerController) {
    UUserWidget *wbItemInstance = UWidgetBlueprintLibrary::Create(
        GetWorld(), widgetClass, playerController);
    UWBItem *wbItem = Cast<UWBItem>(wbItemInstance);
    if (wbItem) {
      wbItem->SetCharacter(character);
    }

    wbItemInstance->AddToViewport(0);
  }
}
