#include "ItemEffect.h"
#include "CoreMinimal.h"
#include <lua.hpp>

int ItemEffect::Heal(lua_State *L) {
  UE_LOG(LogTemp, Warning, TEXT("Heal"));
  return 0;
}
