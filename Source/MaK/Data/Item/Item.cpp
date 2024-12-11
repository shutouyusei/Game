#include "Item.h"
#include "../../Character/MaKCharacter.h"
#include "../../LuaHandler/LuaHandler.h"

Item::Item(AMaKCharacter *ch) { owner_ = ch; }

Item::~Item() {}

void Item::Use(const FString item_name) {
  if (item_name.IsEmpty()) {
    UE_LOG(LogTemp, Warning, TEXT("[Item]item_name is empty"));
    return;
  }
  // LuaHandlerのインスタンスを作成
  LuaHandler *lua_handler = new LuaHandler(LuaPath(item_name).c_str());
  // LuaHandlerに関数を登録
  SetFunctions(lua_handler);
  // Luaを実行
  if (!(lua_handler->executeLua())) {
    // fail
    UE_LOG(LogTemp, Warning, TEXT("[Item]Lua Error"));
    UE_LOG(LogTemp, Warning, TEXT("[Item]item_name: %s"), *item_name);
  }
}

#define LUA_PATH "D:/UEDocument/MaK/Source/Lua/Item/"

std::string Item::LuaPath(const FString lua_path) {
  std::string path = std::string(TCHAR_TO_UTF8(*lua_path));
  return LUA_PATH + path + ".lua";
}
/**
 * Use function
 */

void Item::SetFunctions(LuaHandler *lua_handler) {
  const luaL_Reg functions[] = {
    {"Heal",Heal() },
    {nullptr, nullptr},
  }; 
  const int size = sizeof(functions) / sizeof(functions[0]);
  lua_handler->setFunctionsForLua("item", functions, size);
}


luaFunction Item::Heal() {
  return  [](lua_State *L) -> int { 
    lua_getglobal(L, "heal");
    float heal = lua_tonumber(L, -1);
    UE_LOG(LogTemp, Warning, TEXT("[Item]Heal: %f"), heal);
    return 1;
  };
}
