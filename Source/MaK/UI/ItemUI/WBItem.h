#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "WBItemSlot.h"

#include "WBItem.generated.h"

class UItemDataBase;
struct FItemInstanceData;

UCLASS()
class UWBItem : public UUserWidget {
  GENERATED_BODY()
public:
  // UI
  void SetItemSlots();

  void AddItemSlot(FBelonging &belonging);
  void RemoveItemSlot();

private:
private:
  TArray<UWBItemSlot *> itemSlotWidgets_;
};
