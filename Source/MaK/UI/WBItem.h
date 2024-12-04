#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "WBItem.generated.h"

class AMaKCharacter;

UCLASS()
class UWBItem : public UUserWidget {
  GENERATED_BODY()
public:
  UFUNCTION(BlueprintCallable)
  void UseItem(const int id);
  void SetCharacter(AMaKCharacter *ch);

private:
  AMaKCharacter *character;
};
