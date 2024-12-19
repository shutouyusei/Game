#pragma once
#include "DataBase.h"

class DataBaseFactory {
public:
  virtual DataBase *Create() = 0;
};
