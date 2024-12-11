#include "LuaHandler.h"

LuaHandler::LuaHandler(const char *lua_path) {
  luaL_openlibs(lua_state_);
  luaL_loadfile(lua_state_, lua_path);
};

LuaHandler::~LuaHandler() { lua_close(lua_state_); };

bool LuaHandler::executeLua() {
  if (lua_pcall(lua_state_, 0, 0, 0) == 0) {
    // success
    // WARNING:　実際にオブジェクトを自身で削除できるか不明
    return true;
  }
  return false;
}

void LuaHandler::setFunctionsForLua(const char *library_name,
                                    const luaL_Reg *mylib, const int size) {
  //  luaL_newlib()
  luaL_checkversion(lua_state_);
  // NOTE:配列の最大indexを与えるので size-1
  lua_createtable(lua_state_, 0, size - 1);
  luaL_setfuncs(lua_state_, mylib, 0);
  //
  lua_setglobal(lua_state_, library_name);
}
