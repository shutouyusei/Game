#pragma once
#include "CoreMinimal.h"

class UWBItem;
class UWBItemSlot;
class UUserWidget;

class UIManager {
public:
  UIManager();
  void SetItemUI();

  template <typename T> static T *CreateUI(const FString &path);


private:
  UWBItem *wbItemInstance_;

private:
};
