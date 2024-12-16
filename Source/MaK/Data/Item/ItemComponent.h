#pragma once

#include "../Belonging.h"
#include "ItemDataBase.h"
#include "CoreMinimal.h"

class ItemUseHandler;

class ItemComponent {
public:
  // setup
  ItemComponent();
  ~ItemComponent();
  // setupbelongings
  void SetUpBelongings();
  // get belongings
  UserBelongings *GetUserBelongings() { return userBelongings_; }
  // Use
  void UseItem(const int id);
  //discard
  void DiscardItem(const int id, const int num);

private:
private:
  UserBelongings *userBelongings_;
  ItemUseHandler *useItemHandler_;
};
