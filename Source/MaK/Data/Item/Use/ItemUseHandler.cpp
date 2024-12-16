#include "ItemUseHandler.h"
#include "../../../GameInstance/MyGameInstance.h"
#include "../../../LuaHandler/LuaHandler.h"
#include "ItemEffect.h"

ItemUseHandler::ItemUseHandler() {}

ItemUseHandler::~ItemUseHandler() {}

bool ItemUseHandler::Use(const FString itemName) {
  if (itemName.IsEmpty()) {
    UE_LOG(LogTemp, Warning, TEXT("[ItemUseHandler]itemName is empty"));
    return false;
  }
  // LuaHandlerのインスタンスを作成
  std::string luaPath = LuaPath(itemName);
  LuaHandler *luaHandler = new LuaHandler(luaPath.c_str());
  // LuaHandlerに関数を登録
  SetFunctions(luaHandler);
  // Luaを実行
  return luaHandler->ExecuteLua();
}

#define LUA_PATH "D:/UEDocument/MaK/Source/Lua/ItemUseHandler/"

std::string ItemUseHandler::LuaPath(const FString luaPath) {
  std::string path = std::string(TCHAR_TO_UTF8(*luaPath));
  return LUA_PATH + path + ".lua";
}
/**
 * Use function
 */

void ItemUseHandler::SetFunctions(LuaHandler *luaHandler) {
  const luaL_Reg functions[] = {
      {"test", ItemEffect::Test},
      {nullptr, nullptr},
  };
  const int size = sizeof(functions) / sizeof(functions[0]);
  luaHandler->SetFunctionsForLua("ItemUseHandler", functions, size);
}

// static functions
