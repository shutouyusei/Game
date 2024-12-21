#pragma once
#include "ItemData.h"
#include "../DataBase.h"

class ItemDataBaseComponent {
public:
  ItemDataBaseComponent();
  ~ItemDataBaseComponent();
  void ComponentSetUp();
  FItemData *FetchData(const int id);

private:
  bool isSetUp_ = false;
  static DataBase<FItemData> *fItemDataBase_;
};
