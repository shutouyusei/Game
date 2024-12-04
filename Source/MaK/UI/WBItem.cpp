#include "WBItem.h"
#include "../Character/MaKCharacter.h"
#include "../Data/Item/ItemComponent.h"

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
void UWBItem::SetCharacter(AMaKCharacter *ch) { this->character = ch; }
