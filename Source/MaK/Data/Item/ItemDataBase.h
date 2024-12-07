#pragma once
#include "CoreMinimal.h"
#include "Struct/ItemData.h"
#include "Struct/ItemInstanceData.h"
#include "UObject/Object.h"
#include "UObject/SoftObjectPath.h"

#include "ItemDataBase.generated.h"

class UDataTable;
class UMyGameInstance;
struct FStreamableHandle;

UCLASS()
class UItemDataBase : public UObject {
  GENERATED_BODY()
public:
  UItemDataBase();
  ~UItemDataBase();
  void BeginPlay(UMyGameInstance *game);
  // find data
  const FItemInstanceData *FetchItem(const int primaryID);

private:
  void LoadPath();
  void LoadData();
  void LoadAbilityBookData();
  void LoadImportantData();
  void LoadItemData();
  void LoadMaterialData();
  void LoadUseableData();
  const FItemInstanceData *FetchItemInstanceData(const int primaryID,
                                                 const EItemDataType type);
  const FItemData *FetchItemData(const int primaryID);
  const FItemInstanceData *FetchAbilityBookData(const int primaryID);
  const FItemInstanceData *FetchImportantData(const int primaryID);
  const FItemInstanceData *FetchMaterialData(const int primaryID);
  const FItemInstanceData *FetchUseableData(const int primaryID);

public:
private:
  // game instance
  UMyGameInstance *gameInstance;
  // async load
  TArray<FSoftObjectPath> paths;
  TSharedPtr<FStreamableHandle> streamableHandle;
  // data
  TObjectPtr<UDataTable> abilityBookData;
  TObjectPtr<UDataTable> importantData;
  TObjectPtr<UDataTable> itemData;
  TObjectPtr<UDataTable> materialData;
  TObjectPtr<UDataTable> useableData;

};
