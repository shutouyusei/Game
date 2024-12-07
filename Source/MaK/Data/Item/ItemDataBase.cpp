#include "ItemDataBase.h"
#include "../../GameInstance/MyGameInstance.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"

#define ABILITY_PATH "/Game/Data/Item/DT_AbilityBookData.DT_AbilityBookData"
#define IMPORTANT_PATH "/Game/Data/Item/DT_ImportantData.DT_ImportantData"
#define ITEM_PATH "/Game/Data/Item/DT_ItemData.DT_ItemData"
#define MATERIAL_PATH "/Game/Data/Item/DT_MaterialData.DT_MaterialData"
#define USEABLE_PATH "/Game/Data/Item/DT_UseableData.DT_UseableData"

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

// Fetch Data from PrimaryID

const FItemInstanceData *UItemDataBase::FetchItem(const int primaryID) {
  const FItemData *item = FetchItemData(primaryID);
  if (item == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]FetchItemData is null"));
    return nullptr;
  }
  return FetchItemInstanceData(item->id, item->type);
}

// private
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
  abilityBookData = abilityDataPtr.Get();
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

const FItemInstanceData *
UItemDataBase::FetchItemInstanceData(const int primaryID,
                                     const EItemDataType type) {
  switch (type) {
  case EItemDataType::AbilityBook:
    return FetchAbilityBookData(primaryID);
  case EItemDataType::Important:
    return FetchImportantData(primaryID);
  case EItemDataType::Material:
    return FetchMaterialData(primaryID);
  case EItemDataType::Useable:
    return FetchUseableData(primaryID);
  default:
    return nullptr;
  }
}

const FItemInstanceData *
UItemDataBase::FetchAbilityBookData(const int primaryID) {
  if (abilityBookData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]abilityBookData is null"));
    abilityBookData =
        LoadObject<UDataTable>(NULL, TEXT(ABILITY_PATH), NULL, LOAD_None, NULL);
  }
  const FItemInstanceData *ability =
      abilityBookData->FindRow<FItemInstanceData>(
          FName(*FString::FromInt(primaryID)), "");
  return ability;
}

const FItemInstanceData *
UItemDataBase::FetchImportantData(const int primaryID) {
  if (importantData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]importantData is null"));
    importantData = LoadObject<UDataTable>(NULL, TEXT(IMPORTANT_PATH), NULL,
                                           LOAD_None, NULL);
  }
  const FItemInstanceData *important =
      importantData->FindRow<FItemInstanceData>(
          FName(*FString::FromInt(primaryID)), "");
  return important;
}

const FItemInstanceData *UItemDataBase::FetchMaterialData(const int primaryID) {
  if (materialData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]materialData is null"));
    materialData = LoadObject<UDataTable>(NULL, TEXT(MATERIAL_PATH), NULL,
                                          LOAD_None, NULL);
  }
  const FItemInstanceData *material = materialData->FindRow<FItemInstanceData>(
      FName(*FString::FromInt(primaryID)), "");
  return material;
}

const FItemInstanceData *UItemDataBase::FetchUseableData(const int primaryID) {
  if (useableData == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]useableData is null"));
    useableData =
        LoadObject<UDataTable>(NULL, TEXT(USEABLE_PATH), NULL, LOAD_None, NULL);
  }
  const FItemInstanceData *useable = useableData->FindRow<FItemInstanceData>(
      FName(*FString::FromInt(primaryID)), "");
  return useable;
}
