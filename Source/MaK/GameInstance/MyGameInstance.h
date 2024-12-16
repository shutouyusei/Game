#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"

#include "MyGameInstance.generated.h"

class UItemDataBase;
class UEquipmentDataBase;
class AMaKCharacter;

UCLASS()
class MAK_API UMyGameInstance : public UGameInstance {
  GENERATED_BODY()
public:
  static AMaKCharacter *playerCharacter;

private:
  FStreamableManager streamableManager;
  // database
  TObjectPtr<UItemDataBase> itemDataBase;
  TObjectPtr<UEquipmentDataBase> equipmentDataBase;

public:
  void Init() override;
  void Shutdown() override;
  //
  FStreamableManager *GetStreamableManager() { return &streamableManager; };
  // databaase
  UItemDataBase *GetItemDataBase() { return itemDataBase; };
  UEquipmentDataBase *GetEquipmentDataBase() { return equipmentDataBase; };
  // NOTE:静的関数 どこからでも呼び出せるインスタンスの取得
  static UMyGameInstance *GetInstance();

private:
  void SetDataBase();
  void SetPlayerCharacter();
};
