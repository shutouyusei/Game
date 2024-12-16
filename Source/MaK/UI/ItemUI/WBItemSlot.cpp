#include "WBItemSlot.h"
#include "../../Data/Item/ItemComponent.h"
#include "../../GameInstance/MyGameInstance.h"

void UWBItemSlot::SetItemDetails(Belonging &belongingData,
                                 const FItemInstanceData *itemInstanceData) {
  // set method
  belonging_ = &belongingData;
  // itemInstanceDataから必要なデータwoコピー
  // itemComponent_ = character->GetItemComponent();
}

void UWBItemSlot::UseItem() { itemComponent_->UseItem(belonging_->id); }
