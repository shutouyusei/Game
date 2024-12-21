#include "DataTableFactory.h"

UDataTable *DataTableFactory::SyncLoad(FString path) {
  UDataTable *table = nullptr;
  //NOTE: 強制終了する場合データのパスが間違っている可能性が高い
  table = LoadObject<UDataTable>(nullptr, *path, nullptr, LOAD_None, nullptr);
  if (table == nullptr) {
    FString msg = TEXT("[DataTableFactory]Failed to load DataTable");
    throw msg;
  }
  return table;
}
  // TODO:AsyncLoad
