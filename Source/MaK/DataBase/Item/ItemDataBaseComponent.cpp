#include "ItemDataBaseComponent.h"
#include "ItemData.h"
#include "ItemDataBaseFactory.h"

//TODO: Add item struct and fetch function
DataBase<FItemData> *ItemDataBaseComponent::fItemDataBase_ = nullptr;

ItemDataBaseComponent::ItemDataBaseComponent() {}

void ItemDataBaseComponent::ComponentSetUp() {
  ItemDataBaseFactory factory;
  try {
    isSetUp_ = true;
    ItemDataBaseComponent::fItemDataBase_ = factory.CreateFItem();
  } catch (FString msg) {
    UE_LOG(LogTemp, Error, TEXT("%s"), *msg);
  }
}

ItemDataBaseComponent::~ItemDataBaseComponent() {
  if (isSetUp_) {
    fItemDataBase_ = nullptr;
  }
}

FItemData *ItemDataBaseComponent::FetchData(const int id) {
  try {
    if (ItemDataBaseComponent::fItemDataBase_ == nullptr) {
      FString msg = TEXT("[ItemDataBaseComponent]ItemDataBase is not set");
      throw msg;
    }
    FItemData *data = ItemDataBaseComponent::fItemDataBase_->AccessDataBase(id);
    return data;
  } catch (FString msg) {
    UE_LOG(LogTemp, Error, TEXT("%s"), *msg);
    return nullptr;
  }
}
