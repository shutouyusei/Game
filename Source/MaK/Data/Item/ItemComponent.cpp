#include "ItemComponent.h"
#include "../../Character/MaKCharacter.h"
#include "../../GameInstance/MyGameInstance.h"
#include "../Belonging.h"
#include "Item.h"
#include "ItemDataBase.h"

UItemComponent::UItemComponent() {
  // TODO:セーブデータから所持品読み込み
  belongings_ = new Belongings();
}

UItemComponent::~UItemComponent() {}

// NOTE:this function must call after create this component in character
void UItemComponent::SetUpItemComponent(AMaKCharacter *character) {
  owner_ = character;
  useableItem_ = new Item(character);
}
void UItemComponent::BeginPlay() {
  Super::BeginPlay();
  itemDataBase_ = UMyGameInstance::GetInstance()->GetItemDataBase();
}

// UseItem
void UItemComponent::UseItem(const int id) {
  const FItemInstanceData *itemInstance = itemDataBase_->FetchItem(id);
  // itemInstance->Use(useable->itemPath);
  const FString item_path = itemInstance->itemPath;
  useableItem_->Use(item_path);
}
