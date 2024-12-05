#include "Item.h"
#include "../../Character/MaKCharacter.h"

#include "lua.hpp"

#include "lualib.h"

#include "lauxlib.h"

Item::Item(AMaKCharacter *ch) {
  owner = ch;
}

Item::~Item() { }

void Item::Use(const FString lua_path) {
  lua_State *L = luaL_newstate();
  UE_LOG(LogTemp, Warning, TEXT(LUA_PATH));
  UE_LOG(LogTemp, Warning, TEXT("%s"), *lua_path);
  UE_LOG(LogTemp, Warning, TEXT(".lua") );
  luaL_openlibs(L);
  std::string itemPath = LuaPath(lua_path);
  luaL_loadfile(L,itemPath.c_str());
  // 関数呼び出し
  lua_pcall(L, 0, 1, 0);
  int n = lua_tointeger(L, -1);
  lua_pop(L, 1);
  UE_LOG(LogTemp, Warning, TEXT("[Lua]Return Value:%d"), n);
  lua_close(L);
}

std::string Item::LuaPath(const FString lua_path) {
  std::string path = std::string(TCHAR_TO_UTF8(*lua_path));
  return LUA_PATH + path + ".lua";
} 
/**
 * Use function
 */

int Item::Heal(lua_State *L) {
  UE_LOG(LogTemp, Warning, TEXT("[Lua]Heal"));
  return 1;
}
