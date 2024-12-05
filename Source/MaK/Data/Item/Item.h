#pragma once

#include "CoreMinimal.h"

class AMaKCharacter;
struct lua_State;

#define LUA_PATH "D:/UEDocument/MaK/Source/Lua/Item/"

class Item {
public:
  Item(AMaKCharacter *ch);
  void Use(const FString lua_path);

private:
  // アイテムの使用の関数
  int Heal(lua_State *lua);

private:
  AMaKCharacter *owner;
};
