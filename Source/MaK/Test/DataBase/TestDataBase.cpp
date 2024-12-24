#include "../Test.h"
#include "ItemDataBaseComponent.h"

//  ItemDataBase
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemDataBaseTest,
                                 "DataBase.ItemDataComponent",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FItemDataBaseTest::RunTest(const FString &Parameters) {
  UE_LOG(LogTemp, Warning, TEXT("FItemDataBaseTest"));
  TestHelper helper;

  ItemDataBaseComponent itemDataBaseComponent;
  itemDataBaseComponent.ComponentSetUp();
  FItemData *ret = itemDataBaseComponent.FetchFItemData(1);
  helper.NotNull(ret, "ItemDataBaseComponent FetchData is NULL");
  ItemDataBaseComponent itemDataBaseComponent2;
  ret = itemDataBaseComponent2.FetchFItemData(1);
  helper.NotNull(ret, "ItemDataBaseComponent FetchData is NULL");
  return helper.IsTest();
}
