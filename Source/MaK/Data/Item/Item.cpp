#include "Item.h"
#include "../../Character/MaKCharacter.h"
#include <iostream>
#include <string.h>

#include "lua.hpp"

#include "lualib.h"

#include "lauxlib.h"

Item::Item(AMaKCharacter *ch) {
  owner = ch;
  // 関数を登録
}

void Item::Use(const FString lua_path) {
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  std::string path = TCHAR_TO_ANSI(*lua_path);
  std::string itemPath = LUA_PATH + path + ".lua";
  luaL_loadfile(L, "D:/UEDocument/MaK/Source/Lua/Item/item.lua");
  // 関数呼び出し
  lua_pcall(L, 0, 1, 0);
  int n = lua_tointeger(L, -1);
  lua_pop(L, 1);
  UE_LOG(LogTemp, Warning, TEXT("[Lua]Return Value:%d"), n);
  lua_close(L);
}

/**
 * Use function
 */

int Item::Heal(lua_State *lua) {
  UE_LOG(LogTemp, Warning, TEXT("[Lua]Heal"));
  return 1;
}
