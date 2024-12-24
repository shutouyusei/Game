#pragma once
#include "../DataBase.h"

struct FItemData;

class ItemDataBaseFactory {
public:
  DataBase<FItemData> *CreateFItem();
};
