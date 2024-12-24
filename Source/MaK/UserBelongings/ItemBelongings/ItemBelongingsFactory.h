#pragma once
#include "../UserBelongingsFactory.h"

class ItemBelongingsFactory : public UserBelongingsFactory {
public:
  virtual UserBelongings *CreateBelongings() override;
};
