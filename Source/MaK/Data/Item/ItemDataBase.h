#pragma once
#include "CoreMinimal.h"
#include "Struct/ItemClassificationData.h"
#include "Struct/ItemInstanceData.h"
#include "UObject/Object.h"
#include "UObject/SoftObjectPath.h"

#include "ItemDataBase.generated.h"

class UDataTable;
class UMyGameInstance;
struct FStreamableHandle;
struct FItemClassificationData;

UCLASS()
class UItemDataBase : public UObject {
  GENERATED_BODY()
public:
  UItemDataBase();
  ~UItemDataBase();
  void BeginPlay(UMyGameInstance *game);
  // find data
  // NOTE:この関数しか使わない
  // ItemIdからItemInstanceDataを取得する
  const FItemInstanceData *FetchItem(const int primaryID);

private:
  void LoadPath();
  void LoadData();
  UDataTable *LoadDataTable(FSoftObjectPath path);

  const FItemInstanceData *
  FetchItemInstanceData(const int primaryID,
                        const EItemClassificationDataType type);
  const FItemClassificationData *
  FetchItemClassificationData(const int primaryID);
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
