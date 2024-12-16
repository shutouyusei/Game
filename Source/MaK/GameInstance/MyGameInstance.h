#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"

#include "MyGameInstance.generated.h"

class ItemComponent;
class UItemDataBase;
class UEquipmentDataBase;
class AMaKCharacter;

UCLASS()
class MAK_API UMyGameInstance : public UGameInstance {
  GENERATED_BODY()
public:
  void Init() override;
  void Shutdown() override;
  //
  FStreamableManager *GetStreamableManager() { return &streamableManager_; };
  // databaase
  UItemDataBase *GetItemDataBase() { return itemDataBase_; };
  UEquipmentDataBase *GetEquipmentDataBase() { return equipmentDataBase_; };
  // player character
  AMaKCharacter *GetPlayerCharacter() { return playerCharacter_; };
  // itemcomponent
  ItemComponent *GetItemComponent() { return itemComponent_; };

  // NOTE:静的関数 どこからでも呼び出せるインスタンスの取得
  static UMyGameInstance *GetInstance();

private:
  void SetDataBase();
  void SetPlayerCharacter();
  void SetItemComponent();

public:
private:
  FStreamableManager streamableManager_;
  // database
  TObjectPtr<UItemDataBase> itemDataBase_;
  TObjectPtr<UEquipmentDataBase> equipmentDataBase_;
  // player character
  AMaKCharacter *playerCharacter_;
  // itemcomponent
  ItemComponent *itemComponent_;
  // static instance
  static UMyGameInstance *instance_;
};
