#include "ItemComponent.h"
#include "../../Character/MaKCharacter.h"
#include "../../GameInstance/MyGameInstance.h"
#include "Item.h"
#include "ItemDataBase.h"
#include "Struct/AbilityBookData.h"
#include "Struct/ItemData.h"
#include "Struct/UseableData.h"

UItemComponent::UItemComponent() {}

UItemDataBase *UItemComponent::GetItemDataBase() {
  UItemDataBase *itemDataBase =
      UMyGameInstance::GetInstance()->GetItemDataBase();
  return itemDataBase;
}

void UItemComponent::CreateItemObject(AMaKCharacter *character) {
  iteminstance = new Item(character);
}

void UItemComponent::AddItem(const int id, const int num) {
  for (FHave &item : haveItems) {
    if (item.id == id) {
      item.num += num;
      return;
    }
  }
  haveItems.Add(FHave(id, num));
}

void UItemComponent::RemoveItem(const int id, const int num) {
  int index = 0;
  for (FHave &item : haveItems) {
    if (item.id == id) {
      if (item.num <= num) {
        haveItems.RemoveAt(index);
      } else {
        item.num -= num;
      }
      return;
    }
    index++;
  }
}

// UseItem
void UItemComponent::UseItem(const int id) {
  UItemDataBase *itemDataBase = GetItemDataBase();
  const FItemData *item = itemDataBase->FetchItemData(id);
  if (item == nullptr) {
    UE_LOG(LogTemp, Error, TEXT("[Use]Item is null"));
    return;
  }
  if (item->type != EItemDataType::Useable) {
    UE_LOG(LogTemp, Error, TEXT("[Use]Item is not Useable"));
    return;
  }
  const FUseableData *useable = itemDataBase->FetchUseableData(item->id);
  itemInstance->Use(useable->itemPath);
}
void UItemComponent::UseAbilityBook(const int id) {
  // TODO: Use
}
