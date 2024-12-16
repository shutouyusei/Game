#include "ItemDataBase.h"
#include "../../GameInstance/MyGameInstance.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"
#include "Struct/ItemClassificationData.h"

// Fetch Data from PrimaryID

// NOTE:この関数しか使わない
const FItemInstanceData *UItemDataBase::FetchItem(const int primaryID) {
  const FItemClassificationData *item = FetchItemClassificationData(primaryID);
  if (item == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]FetchItemData is null"));
    return nullptr;
  }
  const FItemInstanceData *item_instance =
      FetchItemInstanceData(item->id, item->type);
  return item_instance;
}

////
////
///
///

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
// private
#define ABILITY_PATH "/Game/Data/Item/DT_AbilityBookData.DT_AbilityBookData"
#define IMPORTANT_PATH "/Game/Data/Item/DT_ImportantData.DT_ImportantData"
#define ITEM_PATH "/Game/Data/Item/DT_ItemData.DT_ItemData"
#define MATERIAL_PATH "/Game/Data/Item/DT_MaterialData.DT_MaterialData"
#define USEABLE_PATH "/Game/Data/Item/DT_UseableData.DT_UseableData"

void UItemDataBase::LoadPath() {
  paths.Add(FSoftObjectPath(ABILITY_PATH));
  paths.Add(FSoftObjectPath(IMPORTANT_PATH));
  paths.Add(FSoftObjectPath(ITEM_PATH));
  paths.Add(FSoftObjectPath(MATERIAL_PATH));
  paths.Add(FSoftObjectPath(USEABLE_PATH));
}

void UItemDataBase::LoadData() {
  abilityBookData = LoadDataTable(paths[0]);
  importantData = LoadDataTable(paths[1]);
  itemData = LoadDataTable(paths[2]);
  materialData = LoadDataTable(paths[3]);
  useableData = LoadDataTable(paths[4]);
  UE_LOG(LogTemp, Warning, TEXT("[ItemDataBase]LoadData"));
  streamableHandle.Reset();
}

UDataTable *UItemDataBase::LoadDataTable(FSoftObjectPath path) {
  TSoftObjectPtr<UDataTable> dataPtr;
  dataPtr = TSoftObjectPtr<UDataTable>(path).Get();
  return dataPtr.Get();
}

const FItemClassificationData *
UItemDataBase::FetchItemClassificationData(const int primaryID) {
  if (itemData == nullptr) {
    UE_LOG(LogTemp, Warning,
           TEXT("[ItemDataBase]itemClassificationData is null"));
    itemData =
        LoadObject<UDataTable>(NULL, TEXT(ITEM_PATH), NULL, LOAD_None, NULL);
  }
  const FItemClassificationData *item =
      itemData->FindRow<FItemClassificationData>(
          FName(*FString::FromInt(primaryID)), "");
  return item;
}

const FItemInstanceData *
UItemDataBase::FetchItemInstanceData(const int primaryID,
                                     const EItemClassificationDataType type) {
  switch (type) {
  case EItemClassificationDataType::AbilityBook: {
    const FItemInstanceData *item_instance_data =
        FetchAbilityBookData(primaryID);
    return item_instance_data;
  }
  case EItemClassificationDataType::Important: {
    const FItemInstanceData *item_instance_data = FetchImportantData(primaryID);
    return item_instance_data;
  }
  case EItemClassificationDataType::Material: {
    const FItemInstanceData *item_instance_data = FetchMaterialData(primaryID);
    return item_instance_data;
  }
  case EItemClassificationDataType::Useable: {
    const FItemInstanceData *item_instance_data = FetchUseableData(primaryID);
    return item_instance_data;
  }
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
