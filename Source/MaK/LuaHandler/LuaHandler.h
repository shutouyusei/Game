#pragma once

#include "lua.hpp"

//NOTE: luaを扱うときに初期化，lua実行後は必ず解放すること
class LuaHandler {
  LuaHandler(const char *lua_path);
  ~LuaHandler();

public:
  bool executeLua();
  void setFunctionsForLua(const char *library_name, const struct luaL_Reg *mylib);

private:
  lua_State *lua_state_ = luaL_newstate();
};
