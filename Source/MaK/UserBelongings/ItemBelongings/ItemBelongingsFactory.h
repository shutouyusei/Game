#pragma once
#include "../UserBelongingsFactory.h"

class FItemBelongingsFactory : public UserBelongingsFactory {
public:
  virtual UserBelongings *CreateBelongings() override;
};

class FAbilityBookBelongingsFactory : public UserBelongingsFactory {
public:
  virtual UserBelongings *CreateBelongings() override;
};

class FImportantBelongingsFactory : public UserBelongingsFactory {
public:
  virtual UserBelongings *CreateBelongings() override;
};

class MaterialBelongingsFactory : public UserBelongingsFactory {
public:
  virtual UserBelongings *CreateBelongings() override;
};

