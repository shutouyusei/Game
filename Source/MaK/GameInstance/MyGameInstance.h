#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"

#include "MyGameInstance.generated.h"

class UItemDataBase;
class UEquipmentDataBase;

UCLASS()
class MAK_API UMyGameInstance : public UGameInstance {
  GENERATED_BODY()
public:
private:
  FStreamableManager streamableManager;
  TObjectPtr<UItemDataBase> itemDataBase;
  TObjectPtr<UEquipmentDataBase> equipmentDataBase;
public:
  void Init() override;
  void Shutdown() override;
  FStreamableManager *GetStreamableManager() { return &streamableManager; };
  UItemDataBase *GetItemDataBase() { return itemDataBase; };
  UEquipmentDataBase *GetEquipmentDataBase() { return equipmentDataBase;};
  static UMyGameInstance *GetInstance();
private:
  void SetDataBase();
};
