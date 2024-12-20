#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

template <typename T> class DataBase {
public:
  DataBase(UDataTable *table) : table_(table) {};
  T *FetchData(const int id) {
    T *data = table_->FindRow<T>(FName(*FString::FromInt(id)), "");
    return data;
  };

private:
  UDataTable *table_;
};
