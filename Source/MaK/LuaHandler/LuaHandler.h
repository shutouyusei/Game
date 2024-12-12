#pragma once

#include <lua.hpp>

// NOTE: luaを扱うときに初期化，lua実行後は必ず解放すること
class LuaHandler {
public:
  LuaHandler(const char *luaPath);
  ~LuaHandler();

  bool ExecuteLua(void *object);
  void SetFunctionsForLua(const char *libraryName, const luaL_Reg *mylib,
                          const int size);

private:
  lua_State *luaState_ = luaL_newstate();
};
