#include "../../DataBase/Item/ItemDataBaseComponent.h"
#include "../Test.h"

//  ItemDataBase
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemDataBaseTest,
                                 "DataBase.ItemDataComponent",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FItemDataBaseTest::RunTest(const FString &Parameters) {
  TestHelper *helper = new TestHelper();

  ItemDataBaseComponent *itemDataBaseComponent = new ItemDataBaseComponent();
  FItemData *ret = itemDataBaseComponent->FetchData(1);
  helper->NotNull(ret, "ItemDataBaseComponent FetchData is NULL");
  return helper->IsTest();
}
