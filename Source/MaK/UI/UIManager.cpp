#include "UIManager.h"
#include "../Character/MaKCharacter.h"
#include "../GameInstance/MyGameInstance.h"
#include "../UI/ItemUI/WBItem.h"
#include "../UI/ItemUI/WBItemSlot.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

UIManager::UIManager() {}

void UIManager::SetItemUI() {
  // UWBItem
  const FString path = TEXT("/Game/UI/WBItem.WBItem_C");
  UWBItem *wbItemInstance = CreateUI<UWBItem>(path);
  wbItemInstance->AddToViewport(0);
}

// 明示的宣言
template UWBItemSlot *UIManager::CreateUI<UWBItemSlot>(const FString &path);

template <typename T> T *UIManager::CreateUI(const FString &path) {
  AMaKCharacter *character =
      UMyGameInstance::GetInstance()->GetPlayerCharacter();

  TSubclassOf<UUserWidget> widgetClass =
      TSoftClassPtr<UUserWidget>(FSoftObjectPath(*path)).LoadSynchronous();
  APlayerController *playerController =
      UGameplayStatics::GetPlayerController(character, 0);
  if (widgetClass && playerController) {
    UUserWidget *widgetInstance = UWidgetBlueprintLibrary::Create(
        character, widgetClass, playerController);

    T *widget = Cast<T>(widgetInstance);
    return widget;
  } else {
    UE_LOG(LogTemp, Warning, TEXT("Failed to create UI"));
    return nullptr;
  }
}
