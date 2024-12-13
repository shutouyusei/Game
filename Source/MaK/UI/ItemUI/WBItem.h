#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "WBItemSlot.h"

#include "WBItem.generated.h"

class AMaKCharacter;
class UItemDataBase;
struct FItemInstanceData;

UCLASS()
class UWBItem : public UUserWidget {
  GENERATED_BODY()
public:
  // setup
  void SetUpWBItem(AMaKCharacter *ch);

  // UI
  void SetItemSlots();

  void AddItemSlot(FBelonging &belonging);
  void RemoveItemSlot();

private:
private:
  UItemDataBase *itemDataBase_;
  TArray<UWBItemSlot*> itemSlotWidgets_;
};
