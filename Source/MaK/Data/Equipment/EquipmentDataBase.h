
#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/SoftObjectPath.h"

#include "EquipmentDataBase.generated.h"
class UDataTable;
class UMyGameInstance;
struct FAccessoryData;
struct FBottomArmorData;
struct FEquipmentData;
struct FEquipmentEnhancementData;
struct FHeadData;
struct FUpperArmorData;
struct FWeaponData;
struct FStreamableHandle;

#define ACCESSORY_PATH "/Game/Data/Equipment/DT_AccessoryData.DT_AccessoryData"
#define BOTTOMARMOR_PATH                                                       \
  "/Game/Data/Equipment/DT_BottomArmorData.DT_BottomArmorData"
#define EQUIPMENT_PATH "/Game/Data/Equipment/DT_EquipmentData.DT_EquipmentData"
#define EQUIPMENTENHANCEMENT_PATH                                              \
  "/Game/Data/Equipment/"                                                      \
  "DT_EquipmentEnhancementData.DT_EquipmentEnhancementData"
#define HEAD_PATH "/Game/Data/Equipment/DT_HeadData.DT_HeadData"
#define UPPERARMOR_PATH                                                        \
  "/Game/Data/Equipment/DT_UpperArmorData.DT_UpperArmorData"
#define WEAPON_PATH "/Game/Data/Equipment/DT_WeaponData.DT_WeaponData"

UCLASS()
class UEquipmentDataBase : public UObject {
  GENERATED_BODY()
public:
private:
  // game instance
  UMyGameInstance *gameInstance;
  // async load
  TArray<FSoftObjectPath> paths;
  TSharedPtr<FStreamableHandle> streamableHandle;
  // data
  TObjectPtr<UDataTable> accessoryData;
  TObjectPtr<UDataTable> bottomArmorData;
  TObjectPtr<UDataTable> equipmentData;
  TObjectPtr<UDataTable> equipmentEnhancementData;
  TObjectPtr<UDataTable> headData;
  TObjectPtr<UDataTable> upperArmorData;
  TObjectPtr<UDataTable> weaponData;

public:
  UEquipmentDataBase();
  ~UEquipmentDataBase();
  void BeginPlay(UMyGameInstance *game);
  // find data
  // need null check
  const FAccessoryData *FetchAccessoryData(const int primaryID);
  const FBottomArmorData *FetchBottomArmorData(const int primaryID);
  const FEquipmentData *FetchEquipmentData(const int primaryID);
  const FEquipmentEnhancementData *
  FetchEquipmentEnhancementData(const int primaryID);
  const FHeadData *FetchHeadData(const int primaryID);
  const FUpperArmorData *FetchUpperArmorData(const int primaryID);
  const FWeaponData *FetchWeaponData(const int primaryID);

private:
  void LoadPath();
  void LoadData();
  void LoadAccessoryData();
  void LoadBottomArmorData();
  void LoadEquipmentData();
  void LoadEquipmentEnhancementData();
  void LoadHeadData();
  void LoadUpperArmorData();
  void LoadWeaponData();
};
