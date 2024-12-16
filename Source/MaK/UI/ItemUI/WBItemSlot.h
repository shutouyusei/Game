#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "WBItemSlot.generated.h"

struct FBelonging;
struct FItemInstanceData;
class UItemComponent;

UCLASS()
class UWBItemSlot : public UUserWidget {
  GENERATED_BODY()
public:
  UFUNCTION(BlueprintCallable)
  void UseItem();

  void SetItemDetails(FBelonging &belongingData,
                      const FItemInstanceData *itemInstanceData);

  void SetItemSlotData(int id, int num, FItemInstanceData itemInstanceData);

private:
  FBelonging *belonging_;
  UItemComponent *itemComponent_;
};
