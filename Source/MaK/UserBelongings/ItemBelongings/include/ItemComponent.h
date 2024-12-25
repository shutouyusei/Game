#pragma once
#include "../../UserBelongings.h"

enum ItemType { FItem, FAbilityBook, FImportant, Material };

class ItemComponent {
public:
  ItemComponent();
  ~ItemComponent();
  void ComponentSetUp();
  void ComponentCleanUp();
  UserBelongings *GetItemBelongings(ItemType type);

private:
  static UserBelongings *fItemBelongings_;
  static UserBelongings *fAbilityBookBelongings_;
  static UserBelongings *fImportantBelongings_;
  static UserBelongings *fmaterialBelongings_;
};
