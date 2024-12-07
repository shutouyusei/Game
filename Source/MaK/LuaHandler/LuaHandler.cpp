#include "LuaHandler.h"

LuaHandler::LuaHandler(const char *lua_path) {
  luaL_openlibs(lua_state_);
  luaL_loadfile(lua_state_, lua_path);
};

LuaHandler::~LuaHandler() { lua_close(lua_state_); };

bool LuaHandler::executeLua() {
  if (lua_pcall(lua_state_, 0, 0, 0) != 0) {
    // success
    //WARNING:　実際にオブジェクトを自身で削除できるか不明
    delete this;
    return true;
  }
  return false;
}
void LuaHandler::setFunctionsForLua(const char *library_name,  const struct luaL_Reg *mylib) {
  //FIXME:コンパイルエラー C3861 /
  //luaL_register(lua_state_, library_name, mylib);
}
