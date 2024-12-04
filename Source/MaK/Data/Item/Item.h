#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "Item.generated.h"

class AMaKCharacter;

UCLASS(Blueprintable)
class UItem : public UObject {
  GENERATED_BODY()
public:
  UItem();
  void SetOwner(AMaKCharacter *character) { this->owner = character; };
  virtual void Use();

private:
  AMaKCharacter *owner;
};
