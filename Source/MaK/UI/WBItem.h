#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "WBItem.generated.h"

class AMaKCharacter;
class UItemDataBase;
struct FHave;

UCLASS()
class UWBItem : public UUserWidget {
  GENERATED_BODY()
public:
  // setup
  void BeginPlay(AMaKCharacter *ch);
  void SetCharacter(AMaKCharacter *ch);
  // use
  UFUNCTION(BlueprintCallable)
  void UseItem(const int id);

  // UI
  void ShowItem(FHave item);

private:
  AMaKCharacter *character;
  UItemDataBase *itemDataBase;
};
