#include "ItemBelongingsFactory.h"
#include "CoreMinimal.h"
#include "ItemBelongings.h"

// NOTE: This is a test implementation

UserBelongings *FItemBelongingsFactory::CreateBelongings() {
  // TODO: load from save file
  TArray<BelongingAmount> belongings = {BelongingAmount(1, 1),
                                        BelongingAmount(2, 2)};
  return new ItemBelongings(belongings);
}

UserBelongings *FAbilityBookBelongingsFactory::CreateBelongings() {
  TArray<BelongingAmount> belongings = {BelongingAmount(1, 1),
                                        BelongingAmount(2, 2)};
  return new ItemBelongings(belongings);
};

UserBelongings *FImportantBelongingsFactory::CreateBelongings() {
  TArray<BelongingAmount> belongings = {BelongingAmount(1, 1),
                                        BelongingAmount(2, 2)};
  return new ItemBelongings(belongings);
};

UserBelongings *MaterialBelongingsFactory::CreateBelongings() {
  TArray<BelongingAmount> belongings = {BelongingAmount(1, 1),
                                        BelongingAmount(2, 2)};
  return new ItemBelongings(belongings);
};
