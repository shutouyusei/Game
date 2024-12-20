#pragma once
#include "../DataBaseFactory.h"
class DataBase;

class ItemDataBaseFactory : public DataBaseFactory {
public:
  virtual DataBase *Create() override;
};
