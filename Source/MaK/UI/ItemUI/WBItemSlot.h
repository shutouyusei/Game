#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "WBItemSlot.generated.h"

struct FItemInstanceData;
class ItemComponent;
struct Belonging;

UCLASS()
class UWBItemSlot : public UUserWidget {
  GENERATED_BODY()
public:
  UFUNCTION(BlueprintCallable)
  void UseItem();

  void SetItemDetails(Belonging &belongingData,
                      const FItemInstanceData *itemInstanceData);

  void SetItemSlotData(int id, int num, FItemInstanceData itemInstanceData);

private:
  Belonging *belonging_;
  ItemComponent *itemComponent_;
};
