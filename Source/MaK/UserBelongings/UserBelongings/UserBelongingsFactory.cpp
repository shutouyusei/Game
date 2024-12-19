#include "UserBelongingsFactory.h"
#include "../DataBase/DataBase.h"
#include "CoreMinimal.h"
#include "UserBelongings.h"

// NOTE: This is a test implementation
#define TEST

UserBelongings *UserBelongingsFactory::CreateBelongings() {
#ifdef TEST
  TArray<BelongingAmount> belongings = {BelongingAmount(1, 1),
                                        BelongingAmount(2, 2)};
  DataBase *dataBase = new DataBase();
  return new UserBelongings(belongings, dataBase);
#else
#endif
  return nullptr;
}
