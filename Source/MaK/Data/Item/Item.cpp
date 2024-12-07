#include "Item.h"
#include "../../Character/MaKCharacter.h"
#include <iostream>
#include <string.h>
#include "../../LuaHandler/LuaHandler.h"

Item::Item(AMaKCharacter *ch) { owner = ch; }

Item::~Item() {}

void Item::Use(const FString lua_path) {
  //TODO:luaHanderを使ってluaを実行する
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
