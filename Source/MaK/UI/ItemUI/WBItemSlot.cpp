#include "WBItemSlot.h"
#include "../../Character/MaKCharacter.h"
#include "../../Data/Item/ItemComponent.h"
#include "../../GameInstance/MyGameInstance.h"

void UWBItemSlot::SetItemDetails(FBelonging &belongingData,
                                 const FItemInstanceData *itemInstanceData) {
  // set method
  belonging_ = &belongingData;
  // itemInstanceDataから必要なデータwoコピー
  // get item component from player character
  AMaKCharacter *character =
      UMyGameInstance::GetInstance()->GetPlayerCharacter();
  itemComponent_ = character->GetItemComponent();
}

void UWBItemSlot::UseItem() { itemComponent_->UseItem(belonging_->id); }
