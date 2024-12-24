#include "ItemDataBaseComponent.h"
#include "ItemDataBaseFactory.h"

// TODO: Add item struct and fetch function
DataBase<FItemData> *ItemDataBaseComponent::fItemDataBase_ = nullptr;

ItemDataBaseComponent::ItemDataBaseComponent() {}

void ItemDataBaseComponent::ComponentSetUp() {
  ItemDataBaseFactory factory;
  isSetUp_ = true;
  ItemDataBaseComponent::fItemDataBase_ = factory.CreateFItem();
}

ItemDataBaseComponent::~ItemDataBaseComponent() {
  if (isSetUp_) {
    fItemDataBase_ = nullptr;
  }
}

FItemData *ItemDataBaseComponent::FetchData(const int id) {
  if (ItemDataBaseComponent::fItemDataBase_ == nullptr) {
    UE_LOG(LogTemp, Error,
           TEXT("ItemDataBaseComponent::fItemDataBase_ is null"));
  }
  FItemData *data = ItemDataBaseComponent::fItemDataBase_->AccessDataBase(id);
  return data;
}
