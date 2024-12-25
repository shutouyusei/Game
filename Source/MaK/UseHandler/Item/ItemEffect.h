#pragma once

struct lua_State;

class ItemEffect {
public:
  static int Heal(lua_State *L);
};
