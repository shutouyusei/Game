#pragma once

#include "CoreMinimal.h"

class AMaKCharacter;
class LuaHandler;
struct lua_State;
struct luaL_Reg;


class Item {
public:
  Item(AMaKCharacter *ch);
  ~Item();
  void Use(const FString lua_path);

  // アイテムの使用の関数
  // WARNING:この関数はluaから呼び出す関数であるためその他外部から呼び出してはならない
  // NOTE:外部から呼び出せるようStatiで定義
  static int Heal(lua_State *L);

private:
  // 　アイテムパスの管理
  std::string LuaPath(const FString item_name);
  //関数の設定
  void SetFunctions(LuaHandler *lua_handler);

private:
  AMaKCharacter *owner_;
};
