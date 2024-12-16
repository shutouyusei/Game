#include "UseItemHandler.h"
#include "../../Character/MaKCharacter.h"
#include "../../GameInstance/MyGameInstance.h"
#include "../../LuaHandler/LuaHandler.h"
#include "../../Stats/StatsComponent.h"

UseItemHandler::UseItemHandler() {}

UseItemHandler::~UseItemHandler() {}

bool UseItemHandler::Use(const FString itemName) {
  if (itemName.IsEmpty()) {
    UE_LOG(LogTemp, Warning, TEXT("[UseItemHandler]itemName is empty"));
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

#define LUA_PATH "D:/UEDocument/MaK/Source/Lua/UseItemHandler/"

std::string UseItemHandler::LuaPath(const FString luaPath) {
  std::string path = std::string(TCHAR_TO_UTF8(*luaPath));
  return LUA_PATH + path + ".lua";
}
/**
 * Use function
 */

void UseItemHandler::SetFunctions(LuaHandler *luaHandler) {
  const luaL_Reg functions[] = {
      {"test", Test},
      {nullptr, nullptr},
  };
  const int size = sizeof(functions) / sizeof(functions[0]);
  luaHandler->SetFunctionsForLua("UseItemHandler", functions, size);
}

// static functions
int UseItemHandler::Test(lua_State *L) {
  float var1 = luaL_checknumber(L, 1);
  AMaKCharacter *character =
      UMyGameInstance::GetInstance()->GetPlayerCharacter();
  character->GetStatsComponent()->GetStatsHandler()->test();
  UE_LOG(LogTemp, Warning, TEXT("[UseItemHandler]Heal: %f"), var1);
  return 1;
}
