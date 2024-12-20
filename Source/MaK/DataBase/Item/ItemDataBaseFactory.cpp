#include "ItemDataBaseFactory.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

DataBase *ItemDataBaseFactory::Create() {
  UDataTable *table = LoadObject<UDataTable>(
      nullptr, TEXT("DataTable'/Game/Data/DT_ItemData.ItemData'"));
  return new DataBase(table);
}
