#include "ItemDataBaseComponent.h"
#include "ItemDataBaseFactory.h"

// initialize static variables
DataBase<FItemData> *ItemDataBaseComponent::fItemDataBase_ = nullptr;
DataBase<FMaterialData> *ItemDataBaseComponent::fMaterialDataBase_ = nullptr;
DataBase<FAbilityBookData> *ItemDataBaseComponent::fAbilityBookDataBase_ =
    nullptr;
DataBase<FImportantItemData> *ItemDataBaseComponent::fImportantItemDataBase_ =
    nullptr;

//
ItemDataBaseComponent::ItemDataBaseComponent() {}

void ItemDataBaseComponent::ComponentSetUp() {
  ItemDataBaseFactory factory;
  isSetUp_ = true;
  ItemDataBaseComponent::fItemDataBase_ = factory.CreateFItem();
  ItemDataBaseComponent::fMaterialDataBase_ = factory.CreateFMaterial();
  ItemDataBaseComponent::fAbilityBookDataBase_ = factory.CreateFAbilityBook();
  ItemDataBaseComponent::fImportantItemDataBase_ =
      factory.CreateFImportantItem();
}

ItemDataBaseComponent::~ItemDataBaseComponent() {
  if (isSetUp_) {
    fItemDataBase_ = nullptr;
    fMaterialDataBase_ = nullptr;
    fAbilityBookDataBase_ = nullptr;
    fImportantItemDataBase_ = nullptr;
  }
}

FItemData *ItemDataBaseComponent::FetchFItemData(const int id) {
  FItemData *data = ItemDataBaseComponent::fItemDataBase_->AccessDataBase(id);
  return data;
}

FMaterialData *ItemDataBaseComponent::FetchFMaterialData(const int id) {
  FMaterialData *data =
      ItemDataBaseComponent::fMaterialDataBase_->AccessDataBase(id);
  return data;
}

FAbilityBookData *ItemDataBaseComponent::FetchFAbilityBookData(const int id) {
  FAbilityBookData *data =
      ItemDataBaseComponent::fAbilityBookDataBase_->AccessDataBase(id);
  return data;
}

FImportantItemData *
ItemDataBaseComponent::FetchFImportantItemData(const int id) {
  FImportantItemData *data =
      ItemDataBaseComponent::fImportantItemDataBase_->AccessDataBase(id);
  return data;
}
