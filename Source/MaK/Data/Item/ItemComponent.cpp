#include "ItemComponent.h"
#include "../../GameInstance/MyGameInstance.h"
#include "ItemDataBase.h"
#include "Use/ItemUseHandler.h"

ItemComponent::ItemComponent() {
  useItemHandler_ = new ItemUseHandler();
  SetUpBelongings();
}

ItemComponent::~ItemComponent() {}

void ItemComponent::SetUpBelongings() {
  // TODO:セーブデータから所持品読み込み
  if (userBelongings_ == nullptr) {
    userBelongings_ = new UserBelongings();
  }
}
// UseItem
void ItemComponent::UseItem(const int id) {
  UItemDataBase *itemDataBase =
      UMyGameInstance::GetInstance()->GetItemDataBase();
  const FItemInstanceData *itemInstance = itemDataBase->FetchItem(id);

  // itemInstance->Use(useable->itemPath);
  const FString item_path = itemInstance->itemPath;
  bool result = useItemHandler_->Use(item_path);
  // アイテムの使用後の処理
  if (result) {
    // success
    userBelongings_->DecreaseBelongings(id, 1);
  } else {
    // fail
    UE_LOG(LogTemp, Warning, TEXT("[ItemComponent]UseItem: fail"));
  }
}
