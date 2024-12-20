#include "DataBase.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FetchedData.h"

FFetchedData *DataBase::FetchData(const int id) {
  return table_->FindRow<FFetchedData>(FName(*FString::FromInt(id)), "");
}
