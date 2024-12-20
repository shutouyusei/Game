#pragma once
#include "../DataBase.h"
#include "ItemData.h"

class ItemDataBaseComponent {
public:
  ItemDataBaseComponent();
  ~ItemDataBaseComponent();
  FItemData *FetchData(const int id);

private:
  static DataBase<FItemData> *fItemDataBase_;
};
