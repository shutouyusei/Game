#pragma once

#include <lua.hpp>

// NOTE: luaを扱うときに初期化，lua実行後は必ず解放すること
class LuaHandler {
public:
  LuaHandler(const char *lua_path);
  ~LuaHandler();

  bool executeLua();
  void setFunctionsForLua(const char *library_name, const luaL_Reg *mylib,
                          const int size);

private:
  lua_State *lua_state_ = luaL_newstate();
};
