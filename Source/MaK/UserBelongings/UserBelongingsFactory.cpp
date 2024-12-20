#include "UserBelongingsFactory.h"
#include "CoreMinimal.h"
#include "UserBelongings.h"

// NOTE: This is a test implementation

UserBelongings *UserBelongingsFactory::CreateBelongings() {
  TArray<BelongingAmount> belongings = {BelongingAmount(1, 1),
                                        BelongingAmount(2, 2)};
  return new UserBelongings(belongings);
}
