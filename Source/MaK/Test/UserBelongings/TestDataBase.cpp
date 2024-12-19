#include "../../UserBelongings/DataBase/DataBase.h"
#include "../../UserBelongings/DataBase/DataBaseFactory.h"
#include "../../UserBelongings/DataBase/Item/ItemData.h"
#include "../../UserBelongings/DataBase/Item/ItemDataBaseFactory.h"
#include "../Test.h"

bool operator==(FItemData &lhs, FItemData &rhs) {
  FString lhsName = lhs.name;
  FString rhsName = rhs.name;
  FString lhsItem = lhs.item;
  FString rhsItem = rhs.item;
  return lhsName.Equals(rhsName) && lhsItem.Equals(rhsItem);
}

bool operator!=(FItemData &lhs, FItemData &rhs) { return !(lhs == rhs); }

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemDataBaseTest, "DataBase.ItemDataBaseTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FItemDataBaseTest::RunTest(const FString &Parameters) {
  TestHelper *helper = new TestHelper();
  // NOTE:オブジェクト追加ごとに検証
  //  ItemDataBase
  DataBaseFactory *factory = new ItemDataBaseFactory();
  DataBase *itemDataBase = factory->Create();
  helper->NotNull(itemDataBase);
  // fetchTest
  FItemData *itemData = (FItemData *)itemDataBase->FetchData(1);
  helper->NotNull(itemData);
  return helper->IsTest();
}
