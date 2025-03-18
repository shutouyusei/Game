#pragma once
#include "../DataBase.h"

struct FItemData;
struct FAbilityBookData;
struct FMaterialData;
struct FImportantItemData;

class ItemDataBaseFactory {
public:
  DataBase<FItemData> *CreateFItem();
  DataBase<FAbilityBookData> *CreateFAbilityBook();
  DataBase<FMaterialData> *CreateFMaterial();
  DataBase<FImportantItemData> *CreateFImportantItem();

private:
  UDataTable *CreateDataTable(FString &item);
  template <typename T> DataBase<T> *CreateDataBase(FString &item);
  FString itemDataPath_ = TEXT("/Game/Data/Item/");
};
