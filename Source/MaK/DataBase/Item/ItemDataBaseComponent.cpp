#include "ItemDataBaseComponent.h"
#include "ItemData.h"
#include "ItemDataBaseFactory.h"

ItemDataBaseComponent::ItemDataBaseComponent() {
  ItemDataBaseFactory *factory = new ItemDataBaseFactory();
  ItemDataBaseComponent::fItemDataBase_ = factory->Create();
}

ItemDataBaseComponent::~ItemDataBaseComponent() {
  delete ItemDataBaseComponent::fItemDataBase_;
}

FItemData *ItemDataBaseComponent::FetchData(const int id) {
  return ItemDataBaseComponent::fItemDataBase_->FetchData(id);
}

DataBase<FItemData> *ItemDataBaseComponent::fItemDataBase_ = nullptr;
