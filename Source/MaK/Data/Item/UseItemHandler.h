#pragma once

#include "CoreMinimal.h"

class AMaKCharacter;
class LuaHandler;
struct lua_State;
struct luaL_Reg;

class UseItemHandler {
public:
  UseItemHandler(AMaKCharacter *ch);
  ~UseItemHandler();
  bool Use(const FString luaPath);

private:
  // 　アイテムパスの管理
  std::string LuaPath(const FString itemName);
  // 関数の設定
  void SetFunctions(LuaHandler *luaHandler);
  // アイテムの使用の関数
  static int Test(lua_State *L);

private:
  // NOTE:owner_の初期化はSetUpItemComponentで行う
  // luaでの関数実行に静的メンバが必要
  static AMaKCharacter *owner_;
};
