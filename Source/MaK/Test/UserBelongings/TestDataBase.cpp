#include "../../DataBase/DataBase.h"
#include "../../DataBase/DataBaseFactory.h"
#include "../../DataBase/Item/ItemData.h"
#include "../../DataBase/Item/ItemDataBaseFactory.h"
#include "../Test.h"

bool operator==(FItemData &lhs, FItemData &rhs) {
  FString lhsName = lhs.name;
  FString rhsName = rhs.name;
  FString lhsItem = lhs.item;
  FString rhsItem = rhs.item;
  return lhsName.Equals(rhsName) && lhsItem.Equals(rhsItem);
}

bool operator!=(FItemData &lhs, FItemData &rhs) { return !(lhs == rhs); }

//  ItemDataBase
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemDataBaseTest, "DataBase.ItemDataBaseTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FItemDataBaseTest::RunTest(const FString &Parameters) {
  TestHelper *helper = new TestHelper();

  DataBaseFactory *factory = new ItemDataBaseFactory();
  DataBase *itemDataBase = factory->Create();
  helper->NotNull(itemDataBase);
  // fetchTest
  FFetchedData *itemData = itemDataBase->FetchData(1);
  helper->NotNull(itemData);
  return helper->IsTest();
}
