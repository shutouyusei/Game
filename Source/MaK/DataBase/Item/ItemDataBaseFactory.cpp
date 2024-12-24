#include "ItemDataBaseFactory.h"
#include "../DataTableFactory.h"
#include "ItemData.h"

DataBase<FItemData> *ItemDataBaseFactory::CreateFItem() {
  DataTableFactory factory;
  FString path = TEXT("/Game/Data/Item/ItemData.ItemData");
  UDataTable *table = factory.SyncLoad(path);
  DataBase<FItemData> *dataBase = new DataBase<FItemData>();
  dataBase->SetTable(table);
  return dataBase;
}
