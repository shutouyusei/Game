#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "WBItem.generated.h"

class AMaKCharacter;
class UItemDataBase;
struct FItemInstanceData;
struct FBelonging;

struct ItemSlot {
  int id;
  int num;
  const FItemInstanceData *itemInstanceData;
};

UCLASS()
class UWBItem : public UUserWidget {
  GENERATED_BODY()
public:
  // setup
  void SetUpWBItem(AMaKCharacter *ch);
  // use
  UFUNCTION(BlueprintCallable)
  void UseItem(const int id);

  // UI
  void ShowUI();

private:
  ItemSlot SetItemSlot(const FBelonging &belonging);

private:
  AMaKCharacter *character_;
  UItemDataBase *itemDataBase_;
  TArray<ItemSlot> itemSlots_;
};
