#pragma once

class UserBelongings;

class UserBelongingsFactory {
public:
  virtual UserBelongings *CreateBelongings();
};
