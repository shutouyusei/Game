#pragma once

class UserBelongings;

class UserBelongingsFactory {
public:
  virtual UserBelongings *CreateBelongings();

private:
  bool isTest = true;
};
