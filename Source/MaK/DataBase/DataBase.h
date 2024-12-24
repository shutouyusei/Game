#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

template <typename T> class DataBase {
public:
  T *AccessDataBase(const int id) {
    if (!table_) {
      FString msg = TEXT("[DataBase]Table is not set");
    }
    T *data = table_->FindRow<T>(FName(*FString::FromInt(id)), "");
    return data;
  };
  void SetTable(UDataTable *table) { table_ = table; }

private:
  UDataTable *table_;
};
