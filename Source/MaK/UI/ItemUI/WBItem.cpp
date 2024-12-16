#include "WBItem.h"
#include "../../Character/MaKCharacter.h"
#include "../../Data/Item/ItemComponent.h"
#include "../../Data/Item/ItemDataBase.h"
#include "../../GameInstance/MyGameInstance.h"
#include "../UIManager.h"
#include "WBItemSlot.h"

void UWBItem::SetItemSlots() {
  AMaKCharacter *character =
      UMyGameInstance::GetInstance()->GetPlayerCharacter();
  Belongings *belongings = character->GetItemComponent()->GetBelongings();
  // Get belonging instances(所持アイテム)
  // create item slot widget
  for (FBelonging &belonging : belongings->belongings) {
    AddItemSlot(belonging);
  }
}

void UWBItem::AddItemSlot(FBelonging &belonging) {
  // NOTE:blueprint path
  // Set data to item slot widget
  const FString WBItemSlotPath = TEXT("a");
  UWBItemSlot *itemSlotWidget =
      UIManager::CreateUI<UWBItemSlot>(WBItemSlotPath);
  // Get item Data Base
  UItemDataBase *itemDataBase =
      UMyGameInstance::GetInstance()->GetItemDataBase();
  // Fetch item
  const FItemInstanceData *itemInstance = itemDataBase->FetchItem(belonging.id);

  itemSlotWidget->SetItemDetails(belonging, itemInstance);
  itemSlotWidgets_.Add(itemSlotWidget);
}

void UWBItem::RemoveItemSlot() {}
