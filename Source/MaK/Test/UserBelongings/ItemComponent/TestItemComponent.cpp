#include "../../UserBelongings/ItemComponent/ItemComponent.h"
#include "../Test.h"
#include "CoreMinimal.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemComponentTest,
                                 "UserBelongings.ItemComponentTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FItemComponentTest::RunTest(const FString &Parameters) {
  TestHelper *helper = new TestHelper();
  ItemComponent itemComponen;
  itemComponent.ComponentSetUp();
  // get test
  UE_LOG(LogTemp, Warning, TEXT("Testcase 1"));
  TArray<BelongingAmount> *data1 = itemComponent.GetData(ItemType::FItem);
  TArray<BelongingAmount> *data2 =
      itemComponent.GetData(ItemType::FAbilityBook);
  TArray<BelongingAmount> *data3 = itemComponent.GetData(ItemType::FImportant);
  TArray<BelongingAmount> *data4 = itemComponent.GetData(ItemType::Material);
  // Increase test
  UE_LOG(LogTemp, Warning, TEXT("Testcase 2"));
  itemComponent.Increase(1, 1, ItemType::FItem);
  itemComponent.Increase(1, 1, ItemType::FAbilityBook);
  itemComponent.Increase(1, 1, ItemType::FImportant);
  itemComponent.Increase(1, 1, ItemType::Material);
  // Decrease test
  UE_LOG(LogTemp, Warning, TEXT("Testcase 3"));
  itemComponent.Decrease(1, 1, ItemType::FItem);
  itemComponent.Decrease(1, 1, ItemType::FAbilityBook);
  itemComponent.Decrease(1, 1, ItemType::FImportant);
  itemComponent.Decrease(1, 1, ItemType::Material);
  // Use test
  UE_LOG(LogTemp, Warning, TEXT("Testcase 4"));
  itemComponent.UseFItemData(1, ItemType::FItem);
  return helper->IsTest();
}
