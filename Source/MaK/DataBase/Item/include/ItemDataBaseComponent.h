#pragma once
#include "../../DataBase.h"
#include "../AbilityBookData.h"
#include "../ImportantItemData.h"
#include "../ItemData.h"
#include "../MaterialData.h"

class ItemDataBaseComponent {
public:
  ItemDataBaseComponent();
  ~ItemDataBaseComponent();
  // NOTE: this function is called at first and only once
  void ComponentSetUp();
  // NOTE: this function is called at last and only once
  void ComponentCleanUp();

  // interface for database
  FItemData *FetchFItemData(const int id);
  FMaterialData *FetchFMaterialData(const int id);
  FAbilityBookData *FetchFAbilityBookData(const int id);
  FImportantItemData *FetchFImportantItemData(const int id);

private:
  static DataBase<FItemData> *fItemDataBase_;
  static DataBase<FMaterialData> *fMaterialDataBase_;
  static DataBase<FAbilityBookData> *fAbilityBookDataBase_;
  static DataBase<FImportantItemData> *fImportantItemDataBase_;
};
