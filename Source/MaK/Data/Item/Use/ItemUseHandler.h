#pragma once

#include "CoreMinimal.h"

class LuaHandler;
struct lua_State;
struct luaL_Reg;

class ItemUseHandler {
public:
  ItemUseHandler();
  ~ItemUseHandler();
  bool Use(const FString luaPath);

private:
  // 　アイテムパスの管理
  std::string LuaPath(const FString itemName);
  // 関数の設定
  void SetFunctions(LuaHandler *luaHandler);
  // アイテムの使用の関数
  static int Test(lua_State *L);

private:
};
