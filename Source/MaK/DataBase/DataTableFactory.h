#pragma once
#include "CoreMinimal.h"

class DataTableFactory {
public:
  UDataTable *SyncLoad(FString path);
};
