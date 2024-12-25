#pragma once
#include "../UserBelongings.h"

class ItemBelongings : public UserBelongings {
public:
  ItemBelongings(TArray<BelongingAmount> &belongings);
  virtual ~ItemBelongings();
};
