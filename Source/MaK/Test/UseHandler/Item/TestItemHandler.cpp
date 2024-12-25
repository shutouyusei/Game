#include "../../Test.h"
#include "CoreMinimal.h"
#include <Item/FItemUseHandler.h>
#include <ItemDataBaseComponent.h>

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemUseHandlerTest,
                                 "UseHandler.ItemUseHandlerTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FItemUseHandlerTest::RunTest(const FString &Parameters) {
  TestHelper helper;
  ItemDataBaseComponent database;
  database.ComponentSetUp();

  UseHandlerFactory *factory = new FItemUseHandlerFactory();
  UseHandler *handler = factory->Create();
  handler->Use(1);
  delete handler;
  delete factory;
  return helper.IsTest();
}
