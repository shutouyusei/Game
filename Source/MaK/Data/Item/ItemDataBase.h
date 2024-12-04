#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/SoftObjectPath.h"

#include "ItemDataBase.generated.h"

#define ABILITY_PATH "/Game/Data/Item/DT_AbilityBookData.DT_AbilityBookData"
#define IMPORTANT_PATH "/Game/Data/Item/DT_ImportantData.DT_ImportantData"
#define ITEM_PATH "/Game/Data/Item/DT_ItemData.DT_ItemData"
#define MATERIAL_PATH "/Game/Data/Item/DT_MaterialData.DT_MaterialData"
#define USEABLE_PATH "/Game/Data/Item/DT_UseableData.DT_UseableData"
class UDataTable;
class UMyGameInstance;
struct FAbilityBookData;
struct FImportantData;
struct FItemData;
struct FMaterialData;
struct FUseableData;
struct FStreamableHandle;

UCLASS()
class UItemDataBase : public UObject {
  GENERATED_BODY()
public:
private:
  // game instance
  UMyGameInstance *gameInstance;
  // async load
  TArray<FSoftObjectPath> paths;
  TSharedPtr<FStreamableHandle> streamableHandle;
  // data
  TObjectPtr<UDataTable> abilityData;
  TObjectPtr<UDataTable> importantData;
  TObjectPtr<UDataTable> itemData;
  TObjectPtr<UDataTable> materialData;
  TObjectPtr<UDataTable> useableData;

public:
  UItemDataBase();
  ~UItemDataBase();
  void BeginPlay(UMyGameInstance *game);
  // find data
  // need null check
  const FAbilityBookData *FetchAbilityBookData(const int primaryID);
  const FImportantData *FetchImportantData(const int primaryID);
  const FItemData *FetchItemData(const int primaryID);
  const FMaterialData *FetchMaterialData(const int primaryID);
  const FUseableData *FetchUseableData(const int primaryID);

private:
  void LoadPath();
  void LoadData();
  void LoadAbilityBookData();
  void LoadImportantData();
  void LoadItemData();
  void LoadMaterialData();
  void LoadUseableData();
};
