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

void UItemComponent::IncreaseItem(const int id, const int num) {
  for (FHave &item : haveItems) {
    if (item.id == id) {
      item.num += num;
      return;
    }
  }
  AddItem(id, num);
}
void UITemComponent::AddItem(const int id, const int num) {
  haveItems.Add(FHave(id, num));
}

void UItemComponent::DecreaseItem(const int id, const int num) {
  int index = 0;
  for (FHave &item : haveItems) {
    if (item.id != id) {
      index++;
      continue;
    }
    if (item.num <= num) {
      RemoveItem(id);
    } else {
      item.num -= num;
    }
    return;
  }
}
void UItemComponent::RemoveItem(const int id) { haveItems.RemoveAt(id); }

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
