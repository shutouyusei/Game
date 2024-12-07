#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "ItemComponent.h"
#include "ItemDataBase.h"
#include "Kismet/GameplayStatics.h"
#include "Struct/ItemData.h"
#include "Struct/ItemInstanceData.h"

#define ABILITY_PATH "/Game/Data/Item/DT_AbilityBookData.DT_AbilityBookData"
#define IMPORTANT_PATH "/Game/Data/Item/DT_ImportantData.DT_ImportantData"
#define ITEM_PATH "/Game/Data/Item/DT_ItemData.DT_ItemData"
#define MATERIAL_PATH "/Game/Data/Item/DT_MaterialData.DT_MaterialData"
#define USEABLE_PATH "/Game/Data/Item/DT_UseableData.DT_UseableData"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemDataBaseTest, "ItemDataBase.FindTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FItemDataBaseTest::RunTest(const FString &Parameters) {
  bool result = true;
  UDataTable *itemData =
      LoadObject<UDataTable>(NULL, TEXT(ITEM_PATH), NULL, LOAD_None, NULL);
  TArray<FName> rowNames = itemData->GetRowNames();
  UItemDataBase *itemDataBase = NewObject<UItemDataBase>();
  for (const FName rowName : rowNames) {
    const FString rowNameStr = rowName.ToString();
    const int primaryID = FCString::Atoi(*rowNameStr);
    const FItemInstanceData *item = itemDataBase->FetchItem(primaryID);
    if (item == nullptr) {
      result = false;
    }
  }

  return result;
}
// Manage HaveItem
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemComponentTest, "ItemDataBase.AddHaveItem",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FItemComponentTest::RunTest(const FString &Parameters) {
  UItemComponent *itemComponent = NewObject<UItemComponent>();
  itemComponent->IncreaseItem(1, 1);
  itemComponent->IncreaseItem(1, 1);
  itemComponent->IncreaseItem(2, 1);
  FHave haveItem0 = itemComponent->GetHaveItems()[0];
  FHave haveItem1 = itemComponent->GetHaveItems()[1];
  if (haveItem0.id != 1 || haveItem0.num != 2) {
    return false;
  }
  if (haveItem1.id != 2 || haveItem1.num != 1) {
    return false;
  }
  itemComponent->DecreaseItem(1, 1);
  itemComponent->DecreaseItem(2, 1);
  haveItem0 = itemComponent->GetHaveItems()[0];
  if (haveItem0.id != 1 || haveItem0.num != 1) {
    return false;
  }
  if (itemComponent->GetHaveItems().Num() != 1) {
    return false;
  }
  return true;
}
