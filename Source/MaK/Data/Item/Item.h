#pragma once

#include "CoreMinimal.h"

class AMaKCharacter;
struct lua_State;

UCLASS(Blueprintable)
class Item {
public:
  Item(AMaKCharacter *ch);
  void Use(const FString lua_path);

private:
  AMaKCharacter *owner;
  lua_State *L;
};
