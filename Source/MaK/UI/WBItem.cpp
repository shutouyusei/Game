#include "WBItem.h"
#include "../Character/MaKCharacter.h"
#include "../Data/Have.h"
#include "../Data/Item/ItemComponent.h"

#include "../Data/Item/ItemDataBase.h"
#include "../Data/Item/Struct/ItemData.h"
#include "../Data/Item/Struct/ItemInstanceData.h"
#include "../GameInstance/MyGameInstance.h"

void UWBItem::BeginPlay(AMaKCharacter *ch) {
  SetCharacter(ch);
  itemDataBase = UMyGameInstance::GetInstance()->GetItemDataBase();
}
void UWBItem::SetCharacter(AMaKCharacter *ch) { this->character = ch; }

void UWBItem::UseItem(const int id) {
  if (character == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[UI_Item]Character is null"));
    return;
  }
  UItemComponent *itemComponent = character->GetItemComponent();
  if (itemComponent == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[UI_Item]ItemComponent is null"));
    return;
  }
  itemComponent->UseItem(id);
}

void UWBItem::ShowItem(FHave *item) {}
