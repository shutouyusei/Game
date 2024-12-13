#include "WBItem.h"
#include "../Character/MaKCharacter.h"
#include "../Data/Item/ItemComponent.h"
#include "../Data/Item/ItemDataBase.h"
#include "../GameInstance/MyGameInstance.h"

void UWBItem::SetUpWBItem(AMaKCharacter *ch) {
  character_ = ch;
  itemDataBase_ = UMyGameInstance::GetInstance()->GetItemDataBase();
}

void UWBItem::UseItem(const int id) {
  if (character_ == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[UI_Item]Character is null"));
    return;
  }
  UItemComponent *itemComponent = character_->GetItemComponent();
  if (itemComponent == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[UI_Item]ItemComponent is null"));
    return;
  }
  itemComponent->UseItem(id);
}

void UWBItem::ShowUI() {
  Belongings *belongings = character_->GetItemComponent()->GetBelongings();
  const TArray<FBelonging> belongingInstances =
      belongings->GetBelongingInstances();
  TArray<ItemSlot> tmpItemSlots;
  for (const FBelonging &belonging : belongingInstances) {
  tmpItemSlots.Add(SetItemSlot(belonging));
  }
  itemSlots_.Empty();
  itemSlots_ = tmpItemSlots;
}

ItemSlot UWBItem::SetItemSlot(const FBelonging &belonging) {
  //FIXME:構造体をconstしないといけない
  //const変数をh痛の変数に代入できない
  //構造体の初期化について調べる
  ItemSlot itemSlot;
  for (const ItemSlot &i : itemSlots_) {
    if (i.id == belonging.id) {
      itemSlot = i;
      itemSlot.num = belonging.num;
      return itemSlot;
    }
  }
  itemSlot.id = belonging.id;
  itemSlot.num = belonging.num;
  // データベースにアクセス
  itemSlot.itemInstanceData = itemDataBase_->FetchItem(belonging.id); return itemSlot;
}
