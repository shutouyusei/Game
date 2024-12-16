#include "ItemEffect.h"
#include "../../../Character/MaKCharacter.h"
#include "../../../GameInstance/MyGameInstance.h"
#include "../../../LuaHandler/LuaHandler.h"
#include "../../../Stats/StatsComponent.h"

int ItemEffect::Test(lua_State *L) {
  float var1 = luaL_checknumber(L, 1);
  AMaKCharacter *character =
      UMyGameInstance::GetInstance()->GetPlayerCharacter();
  character->GetStatsComponent()->GetStatsHandler()->test();
  UE_LOG(LogTemp, Warning, TEXT("[ItemUseHandler]Heal: %f"), var1);
  return 1;
}
