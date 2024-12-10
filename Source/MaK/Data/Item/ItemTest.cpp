#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "ItemComponent.h"
#include "ItemDataBase.h"
#include "Kismet/GameplayStatics.h"

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
