#pragma once
#include "../DataBase.h"
#include "ItemData.h"

class ItemDataBaseFactory {
public:
  DataBase<FItemData> *Create();
};
