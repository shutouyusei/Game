#include "ItemDataBaseFactory.h"

DataBase<FItemData> *ItemDataBaseFactory::Create() {
  const TCHAR *path = TEXT("Game/Data/ItemData.ItemData");
  // TODO:AsyncLoad
  UDataTable *table =
      LoadObject<UDataTable>(nullptr, path, nullptr, LOAD_None, nullptr);

  DataBase<FItemData> *dataBase = new DataBase<FItemData>(table);
  return dataBase;
}
