#include "Item.h"
#include "../../Character/MaKCharacter.h"
#include <iostream>
#include <lauxlib.h>
#include <lua.hpp>
#include <lualib.h>

Item::Item(AMaKCharacter *ch) {
  owner = ch;
  L = lua_newstate();
  luaL_openlibs(L);
}

void Item::Use(const FString lua_path) {
  std::string path = TCHAR_TO_ANSI(*lua_path);
  luaL_loadfile(L, path.c_str());
  // 関数呼び出し
  lua_getglobal(L, "use");
  if (lua_pcall(L, 0, 0, 0) == 0) {
    UE_LOG(LogTemp, Error, TEXT("[Use]Lua is Error"));
  }
}
