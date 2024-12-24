#include "ItemDataBaseFactory.h"
#include "../DataTableFactory.h"
#include "AbilityBookData.h"
#include "ImportantItemData.h"
#include "ItemData.h"
#include "MaterialData.h"

DataBase<FItemData> *ItemDataBaseFactory::CreateFItem() {
  FString item = TEXT("DT_ItemData");
  return CreateDataBase<FItemData>(item);
}

DataBase<FAbilityBookData> *ItemDataBaseFactory::CreateFAbilityBook() {
  FString item = TEXT("DT_AbilityBookData");
  return CreateDataBase<FAbilityBookData>(item);
}

DataBase<FMaterialData> *ItemDataBaseFactory::CreateFMaterial() {
  FString item = TEXT("DT_MaterialData");
  return CreateDataBase<FMaterialData>(item);
}

DataBase<FImportantItemData> *ItemDataBaseFactory::CreateFImportantItem() {
  FString item = TEXT("DT_ImportantItemData");
  return CreateDataBase<FImportantItemData>(item);
}

UDataTable *ItemDataBaseFactory::CreateDataTable(FString &item) {
  FString path = itemDataPath_ + item + TEXT(".") + item;
  DataTableFactory factory;
  return factory.SyncLoad(path);
}

template <typename T>
DataBase<T> *ItemDataBaseFactory::CreateDataBase(FString &item) {
  UDataTable *table = CreateDataTable(item);
  DataBase<T> *dataBase = new DataBase<T>();
  dataBase->SetTable(table);
  return dataBase;
}
