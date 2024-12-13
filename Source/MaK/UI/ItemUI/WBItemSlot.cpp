#include "WBItemSlot.h"
#include "../../Character/MaKCharacter.h"
#include "../../Data/Item/ItemComponent.h"

void UWBItemSlot::SetItemDetails(FBelonging &belongingData,
                                 const FItemInstanceData *itemInstanceData) {
  // set method
  belonging_ = &belongingData;
  // itemInstanceDataから必要なデータwoコピー
}

void UWBItemSlot::UseItem() {
  AMaKCharacter *character = AMaKCharacter::character_;
  if (character == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[UI_Item]Character is null"));
    return;
  }
  UItemComponent *itemComponent = character->GetItemComponent();
  if (itemComponent == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[UI_Item]ItemComponent is null"));
    return;
  }
  itemComponent->UseItem(belonging_->id);
}
