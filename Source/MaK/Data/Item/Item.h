#pragma once

#include "CoreMinimal.h"

class AMaKCharacter;
class LuaHandler;
struct lua_State;
struct luaL_Reg;

//NOTE:lua用の関数ポインタ
typedef int (*luaFunction)(lua_State *L);

class Item {
public:
  Item(AMaKCharacter *ch);
  ~Item();
  void Use(const FString luaPath);


private:
  // 　アイテムパスの管理
  std::string LuaPath(const FString itemName);
  // 関数の設定
  void SetFunctions(LuaHandler *luaHandler);
  // アイテムの使用の関数
  // NOTE:λ式を返す
  luaFunction Heal();

private:
  AMaKCharacter *owner_;
};
