#include "LuaHandler.h"

LuaHandler::LuaHandler(const char *luaPath) {
  luaL_openlibs(luaState_);
  luaL_loadfile(luaState_, luaPath);
};

LuaHandler::~LuaHandler() { lua_close(luaState_); };

bool LuaHandler::ExecuteLua() {
  if (lua_pcall(luaState_, 0, 0, 0) == 0) {
    // success
    // WARNING:　実際にオブジェクトを自身で削除できるか不明
    return true;
  }
  return false;
}

void LuaHandler::SetFunctionsForLua(const char *libraryName,
                                    const luaL_Reg *mylib, const int size) {
  //  luaL_newlib()
  luaL_checkversion(luaState_);
  // NOTE:配列の最大indexを与えるので size-1
  lua_createtable(luaState_, 0, size - 1);
  luaL_setfuncs(luaState_, mylib, 0);
  //
  lua_setglobal(luaState_, libraryName);
}
