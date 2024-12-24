#include "ItemBelongingsFactory.h"
#include "CoreMinimal.h"
#include "ItemBelongings.h"

// NOTE: This is a test implementation

UserBelongings *ItemBelongingsFactory::CreateBelongings() {
  // TODO: load from save file
  TArray<BelongingAmount> belongings = {BelongingAmount(1, 1),
                                        BelongingAmount(2, 2)};
  return new ItemBelongings(belongings);
}
