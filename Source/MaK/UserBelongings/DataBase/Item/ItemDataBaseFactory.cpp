#include "ItemDataBaseFactory.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemDataBase.h"

DataBase *ItemDataBaseFactory::Create() { return new ItemDataBase(); }
