#include "UserBelongingsFactory.h"
#include "../DataBase/DataBase.h"
#include "CoreMinimal.h"
#include "UserBelongings.h"

// NOTE: This is a test implementation
#define TEST

UserBelongings *UserBelongingsFactory::CreateBelongings() {
#ifdef TEST
  TArray<Belonging> belongings = {Belonging(1, 1), Belonging(2, 2)};
  DataBase *dataBase = new DataBase();
  return new UserBelongings(belongings, dataBase);
#else
#endif
  return nullptr;
}
