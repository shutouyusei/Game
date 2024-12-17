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

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
  TArray<UWBItemSlot *> itemSlotWidgets_;

private:
public:
private:
};
