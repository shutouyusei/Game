#include "WBItem.h"
#include "../Character/MaKCharacter.h"
#include "../Data/Item/ItemComponent.h"
#include "../Data/Item/ItemDataBase.h"
#include "../Data/Have.h"
#include "../Data/Item/Struct/ItemStruct.h"
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

void UWBItem::ShowItem(FHave item){
  const FItemData *fitemData = itemDataBase->fetchItemData(item->id);
  swtich(item->type){
    case EItemDataType::Useable :{
      break;
    }
    case EItemDataType::Material:{
      break;
    }
    case EItemDataType::AbilityBook:{
      break;
    }
    case EItemDataType::Important:{
      break;
    }
  }
}
