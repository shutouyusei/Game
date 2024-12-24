#pragma once
#include "../UserBelongings.h"

class ItemBelongings : public UserBelongings {
public:
  ItemBelongings(TArray<BelongingAmount> &belongings);
  virtual ~ItemBelongings();
  virtual void Use(int id) override;
  virtual void Use(const char *name) override;
};
