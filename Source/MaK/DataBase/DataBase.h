#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

template <typename T> class DataBase {
public:
  T *FetchData(const int id) {
    T *data = table_->FindRow<T>(FName(*FString::FromInt(id)), "");
    return data;
  };
  void SetTable(UDataTable *table) { table_ = table; }

private:
  UDataTable *table_;
};
