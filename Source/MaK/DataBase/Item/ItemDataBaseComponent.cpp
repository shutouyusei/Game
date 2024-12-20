#include "ItemDataBaseComponent.h"
#include "ItemData.h"
#include "ItemDataBaseFactory.h"

DataBase<FItemData> *ItemDataBaseComponent::fItemDataBase_ = nullptr;

ItemDataBaseComponent::ItemDataBaseComponent() {
  if(ItemDataBaseComponent::fItemDataBase_ != nullptr) {
    return;
  }
  ItemDataBaseFactory *factory = new ItemDataBaseFactory();
  ItemDataBaseComponent::fItemDataBase_ = factory->Create();
}

ItemDataBaseComponent::~ItemDataBaseComponent() {
  delete ItemDataBaseComponent::fItemDataBase_;
}

FItemData *ItemDataBaseComponent::FetchData(const int id) {
  return ItemDataBaseComponent::fItemDataBase_->FetchData(id);
}

