#include "ItemDataBase.h"
#include "../../GameInstance/MyGameInstance.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"
#include "Struct/AbilityBookData.h"
#include "Struct/ImportantData.h"
#include "Struct/ItemData.h"
#include "Struct/MaterialData.h"
#include "Struct/UseableData.h"

UItemDataBase::UItemDataBase() {
  UE_LOG(LogTemp, Warning, TEXT("UItemDataBase_Init"));
}

UItemDataBase::~UItemDataBase() {}

void UItemDataBase::BeginPlay(UMyGameInstance *game) {
  gameInstance = game;
  LoadPath();
  UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]AsyncLoadStart"));
  streamableHandle = gameInstance->GetStreamableManager()->RequestAsyncLoad(
      paths,
      FStreamableDelegate::CreateUObject(this, &UItemDataBase::LoadData));
}
void UItemDataBase::LoadPath() {
  paths.Add(FSoftObjectPath(ABILITY_PATH));
  paths.Add(FSoftObjectPath(IMPORTANT_PATH));
  paths.Add(FSoftObjectPath(ITEM_PATH));
  paths.Add(FSoftObjectPath(MATERIAL_PATH));
  paths.Add(FSoftObjectPath(USEABLE_PATH));
}
void UItemDataBase::LoadData() {
  LoadAbilityBookData();
  LoadImportantData();
  LoadItemData();
  LoadMaterialData();
  LoadUseableData();
  UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]LoadData"));
  streamableHandle.Reset();
}
void UItemDataBase::LoadAbilityBookData() {
  TSoftObjectPtr<UDataTable> abilityDataPtr;
  abilityDataPtr = TSoftObjectPtr<UDataTable>(paths[0]).Get();
  abilityData = abilityDataPtr.Get();
}

void UItemDataBase::LoadImportantData() {
  TSoftObjectPtr<UDataTable> importantDataPtr;
  importantDataPtr = TSoftObjectPtr<UDataTable>(paths[1]).Get();
  importantData = importantDataPtr.Get();
}

void UItemDataBase::LoadItemData() {
  TSoftObjectPtr<UDataTable> itemDataPtr;
  itemDataPtr = TSoftObjectPtr<UDataTable>(paths[2]).Get();
  itemData = itemDataPtr.Get();
}
void UItemDataBase::LoadMaterialData() {
  TSoftObjectPtr<UDataTable> materialDataPtr;
  materialDataPtr = TSoftObjectPtr<UDataTable>(paths[3]).Get();
  materialData = materialDataPtr.Get();
}

void UItemDataBase::LoadUseableData() {
  TSoftObjectPtr<UDataTable> useableDataPtr;
  useableDataPtr = TSoftObjectPtr<UDataTable>(paths[4]).Get();
  useableData = useableDataPtr.Get();
}

// Fetch Data from PrimaryID
const FAbilityBookData *
UItemDataBase::FetchAbilityBookData(const int primaryID) {
  if (abilityData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]abilityData is null"));
    abilityData =
        LoadObject<UDataTable>(NULL, TEXT(ABILITY_PATH), NULL, LOAD_None, NULL);
  }
  const FAbilityBookData *abilityBook = abilityData->FindRow<FAbilityBookData>(
      FName(*FString::FromInt(primaryID)), "");
  return abilityBook;
}

const FImportantData *UItemDataBase::FetchImportantData(const int primaryID) {
  if (importantData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]importantData is null"));
    importantData = LoadObject<UDataTable>(NULL, TEXT(IMPORTANT_PATH), NULL,
                                           LOAD_None, NULL);
  }
  const FImportantData *important = importantData->FindRow<FImportantData>(
      FName(*FString::FromInt(primaryID)), "");
  return important;
}

const FItemData *UItemDataBase::FetchItemData(const int primaryID) {
  if (itemData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]itemData is null"));
    itemData =
        LoadObject<UDataTable>(NULL, TEXT(ITEM_PATH), NULL, LOAD_None, NULL);
  }
  const FItemData *item =
      itemData->FindRow<FItemData>(FName(*FString::FromInt(primaryID)), "");
  return item;
}

const FMaterialData *UItemDataBase::FetchMaterialData(const int primaryID) {
  if (materialData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]materialData is null"));
    materialData = LoadObject<UDataTable>(NULL, TEXT(MATERIAL_PATH), NULL,
                                          LOAD_None, NULL);
  }
  const FMaterialData *material = materialData->FindRow<FMaterialData>(
      FName(*FString::FromInt(primaryID)), "");
  return material;
}

const FUseableData *UItemDataBase::FetchUseableData(const int primaryID) {
  if (useableData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]useableData is null"));
    useableData =
        LoadObject<UDataTable>(NULL, TEXT(USEABLE_PATH), NULL, LOAD_None, NULL);
  }
  const FUseableData *useable = useableData->FindRow<FUseableData>(
      FName(*FString::FromInt(primaryID)), "");
  return useable;
}
