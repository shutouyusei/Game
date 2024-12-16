#pragma once

#include "../Belonging.h"
#include "CoreMinimal.h"

class UItemDataBase;
class ItemUseHandler;
struct Belonging;

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

private:
private:
  UserBelongings *userBelongings_;
  ItemUseHandler *useItemHandler_;
};
