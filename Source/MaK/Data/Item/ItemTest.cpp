#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "ItemComponent.h"
#include "ItemDataBase.h"
#include "Kismet/GameplayStatics.h"
#include "Struct/AbilityBookData.h"
#include "Struct/ImportantData.h"
#include "Struct/ItemData.h"
#include "Struct/MaterialData.h"
#include "Struct/UseableData.h"

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
    const FItemData *item = itemDataBase->FetchItemData(primaryID);
    if (item == nullptr) {
      UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
      result = false;
      break;
    }
    EItemDataType type = item->type;
    switch (type) {
    case EItemDataType::Useable: {
      const FUseableData *useable = itemDataBase->FetchUseableData(item->id);
      if (useable == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
        result = false;
      }
      break;
    }
    case EItemDataType::Material: {
      const FMaterialData *material = itemDataBase->FetchMaterialData(item->id);
      if (material == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
        result = false;
      }
      break;
    }
    case EItemDataType::AbilityBook: {
      const FAbilityBookData *abilityBook =
          itemDataBase->FetchAbilityBookData(item->id);
      if (abilityBook == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
        result = false;
      }
      break;
    }
    case EItemDataType::Important: {
      const FImportantData *important =
          itemDataBase->FetchImportantData(item->id);
      if (important == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
        result = false;
      }
      break;
    }
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
  itemComponent->AddItem(1, 1);
  itemComponent->AddItem(1, 1);
  itemComponent->AddItem(2, 1);
  FHave haveItem0 = itemComponent->GetHaveItems()[0];
  FHave haveItem1 = itemComponent->GetHaveItems()[1];
  if (haveItem0.id != 1 || haveItem0.num != 2) {
    return false;
  }
  if (haveItem1.id != 2 || haveItem1.num != 1) {
    return false;
  }
  itemComponent->RemoveItem(1, 1);
  itemComponent->RemoveItem(2, 1);
  haveItem0 = itemComponent->GetHaveItems()[0];
  if (haveItem0.id != 1 || haveItem0.num != 1) {
    return false;
  }
  if (itemComponent->GetHaveItems().Num() != 1) {
    return false;
  }
  return true;
}
