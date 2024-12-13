#pragma once
#include "CoreMinimal.h"

class UWBItem;
class AMaKCharacter;
class UWBItemSlot;

class UIManager {
public:
  UIManager(AMaKCharacter *character);
  void SetItemUI();

  template <typename T>
  static T *CreateUI(const FString &path);

private:
  AMaKCharacter *character_;
  UWBItem *wbItemInstance_;

private:
};
