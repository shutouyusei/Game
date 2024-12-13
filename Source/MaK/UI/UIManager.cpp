#include "UIManager.h"
#include "../Character/MaKCharacter.h"
#include "../UI/WBItem.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

UIManager::UIManager(AMaKCharacter *character) { character_ = character; }

void UIManager::SetItemUI() {
  const FString path = TEXT("/Game/UI/WBItem.WBItem_C");
  UWBItem *wbItemInstance = CreateUI<UWBItem>(path);
  wbItemInstance->SetUpWBItem(character_);
  wbItemInstance->AddToViewport(0);
}

template <typename T> T *UIManager::CreateUI(const FString &path) {
  TSubclassOf<UUserWidget> widgetClass =
      TSoftClassPtr<UUserWidget>(FSoftObjectPath(*path)).LoadSynchronous();
  APlayerController *playerController =
      UGameplayStatics::GetPlayerController(character_, 0);
  if (widgetClass && playerController) {
    UUserWidget *widgetInstance = UWidgetBlueprintLibrary::Create(
        character_, widgetClass, playerController);

    T *widget = Cast<T>(widgetInstance);
    return widget;
  }
  return nullptr;
}
