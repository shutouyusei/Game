#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "EquipmentDataBase.h"
#include "Kismet/GameplayStatics.h"
#include "Struct/AccessoryData.h"
#include "Struct/BottomArmorData.h"
#include "Struct/EquipmentData.h"
#include "Struct/EquipmentEnhancementData.h"
#include "Struct/HeadData.h"
#include "Struct/UpperArmorData.h"
#include "Struct/WeaponData.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEquipmentDataBaseTest,
                                 "EquipmentDataBase.FindTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FEquipmentDataBaseTest::RunTest(const FString &Parameters) {
  bool result = true;
  UDataTable *equipmentData =
      LoadObject<UDataTable>(NULL, TEXT(EQUIPMENT_PATH), NULL, LOAD_None, NULL);
  TArray<FName> rowNames = equipmentData->GetRowNames();
  UEquipmentDataBase *equipmentDataBase = NewObject<UEquipmentDataBase>();
  for (const FName rowName : rowNames) {
    const FString rowNameStr = rowName.ToString();
    const int primaryID = FCString::Atoi(*rowNameStr);
    const FEquipmentData *equipment =
        equipmentDataBase->FetchEquipmentData(primaryID);
    if (equipment == nullptr) {
      UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
      result = false;
      break;
    }
    EEquipmentDataType type = equipment->type;
    switch (type) {
    case EEquipmentDataType::Accessory: {
      const FAccessoryData *accessory =
          equipmentDataBase->FetchAccessoryData(primaryID);
      if (accessory == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
        result = false;
        break;
      }
      break;
    }
    case EEquipmentDataType::BottomArmor: {
      const FBottomArmorData *bottomArmor =
          equipmentDataBase->FetchBottomArmorData(primaryID);
      if (bottomArmor == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
        result = false;
        break;
      }
      break;
    }
    case EEquipmentDataType::Head: {
      const FHeadData *head = equipmentDataBase->FetchHeadData(primaryID);
      if (head == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
        result = false;
        break;
      }
      break;
    }
    case EEquipmentDataType::UpperArmor: {
      const FUpperArmorData *upperArmor =
          equipmentDataBase->FetchUpperArmorData(primaryID);
      if (upperArmor == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
        result = false;
        break;
      }
      break;
    }
    case EEquipmentDataType::Weapon: {
      const FWeaponData *weapon = equipmentDataBase->FetchWeaponData(primaryID);
      if (weapon == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("%s is null"), *rowNameStr);
        result = false;
        break;
      }
      break;
    }
    }
  }
  return result;
}
