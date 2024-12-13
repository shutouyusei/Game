#include "ItemComponent.h"
#include "../../Character/MaKCharacter.h"
#include "../../GameInstance/MyGameInstance.h"
#include "ItemDataBase.h"
#include "UseItemHandler.h"

UItemComponent::UItemComponent() { belongings_ = new Belongings(); }

UItemComponent::~UItemComponent() {}

// NOTE:this function must call after create this component in character
void UItemComponent::SetUpItemComponent(AMaKCharacter *character) {
  owner_ = character;
  useItemHandler_ = new UseItemHandler(character);
}

void UItemComponent::SetUpBelongings() {
  // TODO:セーブデータから所持品読み込み
  if (belongings_ == nullptr) {
    belongings_ = new Belongings();
  }
}
void UItemComponent::BeginPlay() {
  Super::BeginPlay();

  itemDataBase_ = UMyGameInstance::GetInstance()->GetItemDataBase();
  SetUpBelongings();
}

// UseItem
void UItemComponent::UseItem(const int id) {
  const FItemInstanceData *itemInstance = itemDataBase_->FetchItem(id);
  // itemInstance->Use(useable->itemPath);
  const FString item_path = itemInstance->itemPath;
  bool result = useItemHandler_->Use(item_path);
  // アイテムの使用後の処理
  if (result) {
    // success
    belongings_->DecreaseBelongings(id, 1);
  } else {
    // fail
    UE_LOG(LogTemp, Warning, TEXT("[UItemComponent]UseItem: fail"));
  }
}
