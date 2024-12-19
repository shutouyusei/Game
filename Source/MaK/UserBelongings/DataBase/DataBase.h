#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FetchedData.h"

class DataBase {
public:
  virtual FFetchedData *FetchData(const int id) = 0;
};
