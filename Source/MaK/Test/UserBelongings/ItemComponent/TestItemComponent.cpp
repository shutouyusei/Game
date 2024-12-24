#include "../../../UserBelongings/ItemBelongings/ItemComponent.h"
#include "../../Test.h"
#include "CoreMinimal.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemComponentTest,
                                 "UserBelongings.ItemComponentTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FItemComponentTest::RunTest(const FString &Parameters) {
  TestHelper *helper = new TestHelper();
  ItemComponent itemComponent;
  itemComponent.ComponentSetUp();
  // get test
  UE_LOG(LogTemp, Warning, TEXT("Test: get data"));
  itemComponent.GetItemBelongings(ItemType::FItem);
  itemComponent.GetItemBelongings(ItemType::FAbilityBook);
  itemComponent.GetItemBelongings(ItemType::FImportant);
  itemComponent.GetItemBelongings(ItemType::Material);
  return helper->IsTest();
}
