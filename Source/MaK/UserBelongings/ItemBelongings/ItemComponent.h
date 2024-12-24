#pragma once
#include "../UserBelongings.h"
#include "CoreMinimal.h"

enum ItemType { FItem, FAbilityBook, FImportant, Material };

class ItemComponent {
public:
  void ComponentSetUp();
  UserBelongings *GetItemBelongings(ItemType type);

private:
  static UserBelongings *fItemBelongings_;
  static UserBelongings *fAbilityBookBelongings_;
  static UserBelongings *fImportantBelongings_;
  static UserBelongings *materialBelongings_;
};
