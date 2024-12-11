#include "Item.h"
#include "../../Character/MaKCharacter.h"
#include "../../LuaHandler/LuaHandler.h"
#include "../../Stats/StatsComponent.h"

Item::Item(AMaKCharacter *ch) { owner_ = ch; }

Item::~Item() {}

void Item::Use(const FString itemName) {
  if (itemName.IsEmpty()) {
    UE_LOG(LogTemp, Warning, TEXT("[Item]itemName is empty"));
    return;
  }
  // LuaHandlerのインスタンスを作成
  LuaHandler *luaHandler = new LuaHandler(LuaPath(itemName).c_str());
  // LuaHandlerに関数を登録
  SetFunctions(luaHandler);
  // Luaを実行
  if (!(luaHandler->ExecuteLua())) {
    // fail
    UE_LOG(LogTemp, Warning, TEXT("[Item]Lua Error"));
    UE_LOG(LogTemp, Warning, TEXT("[Item]itemName: %s"), *itemName);
  }
}

#define LUA_PATH "D:/UEDocument/MaK/Source/Lua/Item/"

std::string Item::LuaPath(const FString luaPath) {
  std::string path = std::string(TCHAR_TO_UTF8(*luaPath));
  return LUA_PATH + path + ".lua";
}
/**
 * Use function
 */

void Item::SetFunctions(LuaHandler *luaHandler) {
  const luaL_Reg functions[] = {
      {"Heal", Heal()},
      {nullptr, nullptr},
  };
  const int size = sizeof(functions) / sizeof(functions[0]);
  luaHandler->SetFunctionsForLua("item", functions, size);
}

luaFunction Item::Heal() {
  // FIXME:関数の中にメンバー変数渡せないから泣く
  return [](lua_State *L) -> int {
    float var1 = luaL_checknumber(L, 1);
    UE_LOG(LogTemp, Warning, TEXT("[Item]Heal: %f"), var1);
    return 1;
  };
}
