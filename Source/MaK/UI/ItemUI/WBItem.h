#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "WBItemSlot.h"

#include "WBItem.generated.h"

struct Belonging;

UCLASS()
class UWBItem : public UUserWidget {
  GENERATED_BODY()
public:
  // UI
  void SetItemSlots();

  void AddItemSlot(Belonging &belonging);
  void RemoveItemSlot();

private:
public:
private:
  TArray<UWBItemSlot *> itemSlotWidgets_;
};
