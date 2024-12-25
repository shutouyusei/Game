#include "FItemUseHandler.h"
#include "CoreMinimal.h"
#include "ItemDataBaseComponent.h"
#include "ItemEffect.h"
#include "LuaHandler.h"
#include "Misc/Paths.h"
#include <string>

UseHandler *FItemUseHandlerFactory::Create() { return new FItemUseHandler(); }

void FItemUseHandler::Use(const int id) {
  // Use the item
  ItemDataBaseComponent database;
  FItemData *fItemData = database.FetchFItemData(id);
  //
  std::string itemPath = SetItemPath(fItemData->itemPath_);
  LuaHandler luaHandler(itemPath.c_str());
  // set function for lua
  const luaL_Reg functions[] = {
      {"Heal", ItemEffect::Heal},
      {nullptr, nullptr},
  };
  const int size = sizeof(functions) / sizeof(functions[0]);
  luaHandler.SetFunctionsForLua("item", functions, size);
  // do lua
  bool result = luaHandler.ExecuteLua();
  if (!result) {
    // error
    UE_LOG(LogTemp, Error, TEXT("Lua Error"));
  }
}

std::string FItemUseHandler::SetItemPath(FString itemPath) {
  FString projectDir = FPaths::ProjectDir();
  projectDir.Append("Source/Lua/Item/");
  std::string rootPath = TCHAR_TO_UTF8(*projectDir);
  std::string itemPathStr = TCHAR_TO_UTF8(*itemPath);
  return rootPath + itemPathStr + ".lua";
}
