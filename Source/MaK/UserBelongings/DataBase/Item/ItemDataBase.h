#pragma once
#include "../DataBase.h"

class ItemDataBase : public DataBase {
public:
  virtual FFetchedData *FetchData(const int id) override;
};
