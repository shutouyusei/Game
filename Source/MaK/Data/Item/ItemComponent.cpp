#include "ItemComponent.h"
#include "../../Character/MaKCharacter.h"
#include "../../GameInstance/MyGameInstance.h"
#include "ItemDataBase.h"
#include "Struct/AbilityBookData.h"
#include "Struct/ItemData.h"
#include "Struct/UseableData.h"

#include "lua.hpp"
#include <direct.h> // _getcwd

#include "lualib.h"

#include "lauxlib.h"

UItemComponent::UItemComponent() {}

UItemComponent::~UItemComponent() {}

UItemDataBase *UItemComponent::GetItemDataBase() {
  UItemDataBase *itemDataBase =
      UMyGameInstance::GetInstance()->GetItemDataBase();
  return itemDataBase;
}

void UItemComponent::AddItem(const int id, const int num) {
  for (FHave &item : haveItems) {
    if (item.id == id) {
      item.num += num;
      return;
    }
  }
  haveItems.Add(FHave(id, num));
}

void UItemComponent::RemoveItem(const int id, const int num) {
  int index = 0;
  for (FHave &item : haveItems) {
    if (item.id == id) {
      if (item.num <= num) {
        haveItems.RemoveAt(index);
      } else {
        item.num -= num;
      }
      return;
    }
    index++;
  }
}

// UseItem
void UItemComponent::UseItem(const int id) {
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  UItemDataBase *itemDataBase = GetItemDataBase();
  const FItemData *item = itemDataBase->FetchItemData(id);
  if (item == nullptr) {
    UE_LOG(LogTemp, Error, TEXT("[Use]Item is null"));
    lua_close(L);
    return;
  }
  if (item->type != EItemDataType::Useable) {
    UE_LOG(LogTemp, Error, TEXT("[Use]Item is not Useable"));
    lua_close(L);
    return;
  }
  // const FUseableData *useable = itemDataBase->FetchUseableData(item->id);
  luaL_loadfile(L, "D:/UEDocument/MaK/Source/Lua/Item/item.lua");
  int result = 0;
  if (lua_pcall(L, 0, 0, 0)) {
    UE_LOG(LogTemp, Error, TEXT("[Use]lua_pcall error"));
    lua_close(L);
    return;
  }
}
void UItemComponent::UseAbilityBook(const int id) {
  // TODO: Use
}
