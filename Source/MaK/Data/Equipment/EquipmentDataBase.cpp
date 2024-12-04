
#include "EquipmentDataBase.h"
#include "../../GameInstance/MyGameInstance.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"
#include "Struct/AccessoryData.h"
#include "Struct/BottomArmorData.h"
#include "Struct/EquipmentData.h"
#include "Struct/EquipmentEnhancementData.h"
#include "Struct/HeadData.h"
#include "Struct/UpperArmorData.h"
#include "Struct/WeaponData.h"

UEquipmentDataBase::UEquipmentDataBase() {
  UE_LOG(LogTemp, Warning, TEXT("UEquipmentDataBase_Init"));
}

UEquipmentDataBase::~UEquipmentDataBase() {}

void UEquipmentDataBase::BeginPlay(UMyGameInstance *game) {
  gameInstance = game;
  LoadPath();
  UE_LOG(LogTemp, Warning, TEXT("[EquipmentDataBase]AsyncLoadStart"));
  streamableHandle = gameInstance->GetStreamableManager()->RequestAsyncLoad(
      paths,
      FStreamableDelegate::CreateUObject(this, &UEquipmentDataBase::LoadData));
}
void UEquipmentDataBase::LoadPath() {
  paths.Add(FSoftObjectPath(ACCESSORY_PATH));
  paths.Add(FSoftObjectPath(BOTTOMARMOR_PATH));
  paths.Add(FSoftObjectPath(EQUIPMENT_PATH));
  paths.Add(FSoftObjectPath(EQUIPMENTENHANCEMENT_PATH));
  paths.Add(FSoftObjectPath(HEAD_PATH));
  paths.Add(FSoftObjectPath(UPPERARMOR_PATH));
  paths.Add(FSoftObjectPath(WEAPON_PATH));
}
void UEquipmentDataBase::LoadData() {
  LoadAccessoryData();
  LoadBottomArmorData();
  LoadEquipmentData();
  LoadEquipmentEnhancementData();
  LoadEquipmentData();
  LoadUpperArmorData();
  LoadWeaponData();
  UE_LOG(LogTemp, Warning, TEXT("[EquipmentDataBase]LoadData"));
  streamableHandle.Reset();
}
void UEquipmentDataBase::LoadAccessoryData() {
  TSoftObjectPtr<UDataTable> accessoryDataPtr;
  accessoryDataPtr = TSoftObjectPtr<UDataTable>(paths[0]).Get();
  accessoryData = accessoryDataPtr.Get();
}

void UEquipmentDataBase::LoadBottomArmorData() {
  TSoftObjectPtr<UDataTable> bottomArmorDataPtr;
  bottomArmorDataPtr = TSoftObjectPtr<UDataTable>(paths[1]).Get();
  bottomArmorData = bottomArmorDataPtr.Get();
}

void UEquipmentDataBase::LoadEquipmentData() {
  TSoftObjectPtr<UDataTable> equipmentDataPtr;
  equipmentDataPtr = TSoftObjectPtr<UDataTable>(paths[2]).Get();
  equipmentData = equipmentDataPtr.Get();
}
void UEquipmentDataBase::LoadEquipmentEnhancementData() {
  TSoftObjectPtr<UDataTable> equipmentEnhancementDataPtr;
  equipmentEnhancementDataPtr = TSoftObjectPtr<UDataTable>(paths[3]).Get();
  equipmentEnhancementData = equipmentEnhancementDataPtr.Get();
}

void UEquipmentDataBase::LoadHeadData() {
  TSoftObjectPtr<UDataTable> headDataPtr;
  headDataPtr = TSoftObjectPtr<UDataTable>(paths[4]).Get();
  headData = headDataPtr.Get();
}
void UEquipmentDataBase::LoadUpperArmorData() {
  TSoftObjectPtr<UDataTable> upperArmorDataPtr;
  upperArmorDataPtr = TSoftObjectPtr<UDataTable>(paths[5]).Get();
  upperArmorData = upperArmorDataPtr.Get();
}

void UEquipmentDataBase::LoadWeaponData() {
  TSoftObjectPtr<UDataTable> weaponDataPtr;
  weaponDataPtr = TSoftObjectPtr<UDataTable>(paths[6]).Get();
  weaponData = weaponDataPtr.Get();
}

// Fetch Data from PrimaryID
const FAccessoryData *
UEquipmentDataBase::FetchAccessoryData(const int primaryID) {
  if (accessoryData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[EquipmentDataBase]accessoryData is null"));
    accessoryData = LoadObject<UDataTable>(NULL, TEXT(ACCESSORY_PATH), NULL,
                                           LOAD_None, NULL);
  }
  const FAccessoryData *accessory = accessoryData->FindRow<FAccessoryData>(
      FName(*FString::FromInt(primaryID)), "");
  return accessory;
}

const FBottomArmorData *
UEquipmentDataBase::FetchBottomArmorData(const int primaryID) {
  if (bottomArmorData == nullptr) {
    UE_LOG(LogTemp, Warning,
           TEXT("[EquipmentDataBase]bottomArmorData is null"));
    bottomArmorData = LoadObject<UDataTable>(NULL, TEXT(BOTTOMARMOR_PATH), NULL,
                                             LOAD_None, NULL);
  }
  const FBottomArmorData *bottomArmor =
      bottomArmorData->FindRow<FBottomArmorData>(
          FName(*FString::FromInt(primaryID)), "");
  return bottomArmor;
}

const FEquipmentData *
UEquipmentDataBase::FetchEquipmentData(const int primaryID) {
  if (equipmentData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[EquipmentDataBase]equipmentData is null"));
    equipmentData = LoadObject<UDataTable>(NULL, TEXT(EQUIPMENT_PATH), NULL,
                                           LOAD_None, NULL);
  }
  const FEquipmentData *equipment = equipmentData->FindRow<FEquipmentData>(
      FName(*FString::FromInt(primaryID)), "");
  return equipment;
}

const FEquipmentEnhancementData *
UEquipmentDataBase::FetchEquipmentEnhancementData(const int primaryID) {
  if (equipmentEnhancementData == nullptr) {
    UE_LOG(LogTemp, Warning,
           TEXT("[EquipmentDataBase]equipmentEnhancementData is null"));
    equipmentEnhancementData = LoadObject<UDataTable>(
        NULL, TEXT(EQUIPMENTENHANCEMENT_PATH), NULL, LOAD_None, NULL);
  }
  const FEquipmentEnhancementData *equipmentEnhancement =
      equipmentEnhancementData->FindRow<FEquipmentEnhancementData>(
          FName(*FString::FromInt(primaryID)), "");
  return equipmentEnhancement;
}

const FHeadData *UEquipmentDataBase::FetchHeadData(const int primaryID) {
  if (headData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[EquipmentDataBase]headData is null"));
    headData =
        LoadObject<UDataTable>(NULL, TEXT(HEAD_PATH), NULL, LOAD_None, NULL);
  }
  const FHeadData *head =
      headData->FindRow<FHeadData>(FName(*FString::FromInt(primaryID)), "");
  return head;
}

const FUpperArmorData *
UEquipmentDataBase::FetchUpperArmorData(const int primaryID) {
  if (upperArmorData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[EquipmentDataBase]upperArmorData is null"));
    upperArmorData = LoadObject<UDataTable>(NULL, TEXT(UPPERARMOR_PATH), NULL,
                                            LOAD_None, NULL);
  }
  const FUpperArmorData *upperArmor = upperArmorData->FindRow<FUpperArmorData>(
      FName(*FString::FromInt(primaryID)), "");
  return upperArmor;
}

const FWeaponData *UEquipmentDataBase::FetchWeaponData(const int primaryID) {
  if (weaponData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[EquipmentDataBase]weaponData is null"));
    weaponData =
        LoadObject<UDataTable>(NULL, TEXT(WEAPON_PATH), NULL, LOAD_None, NULL);
  }
  const FWeaponData *weapon =
      weaponData->FindRow<FWeaponData>(FName(*FString::FromInt(primaryID)), "");
  return weapon;
}
