#include "ItemComponent.h"
#include "../../Character/MaKCharacter.h"
#include "../../GameInstance/MyGameInstance.h"
#include "Item.h"
#include "ItemDataBase.h"

UItemComponent::UItemComponent() {}

UItemComponent::~UItemComponent() {}

void UItemComponent::SetUpItemComponent(AMaKCharacter *character) {
  owner = character;
  useableItem = new Item(character);
}

void UItemComponent::BeginPlay() { GetItemDataBase(); }

void UItemComponent::IncreaseItem(const int id, const int num) {
  for (FHave &item : haveItems) {
    if (item.id == id) {
      item.num += num;
      return;
    }
  }
  AddItem(id, num);
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

// UseItem
void UItemComponent::UseItem(const int id) {
  const FItemInstanceData *itemInstance = itemDataBase->FetchItem(id);
  // itemInstance->Use(useable->itemPath);
  useableItem->Use(itemInstance->itemPath);
}

// private
UItemDataBase *UItemComponent::GetItemDataBase() {
  itemDataBase = UMyGameInstance::GetInstance()->GetItemDataBase();
  return itemDataBase;
}

void UItemComponent::AddItem(const int id, const int num) {
  haveItems.Add(FHave(id, num));
}

void UItemComponent::RemoveItem(const int id) { haveItems.RemoveAt(id); }
