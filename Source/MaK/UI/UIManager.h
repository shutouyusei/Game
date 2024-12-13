#pragma once
#include "CoreMinimal.h"

class UWBItem;
class AMaKCharacter;

class UIManager {
public:
  UIManager(AMaKCharacter *character);
  void SetItemUI();

private:
  AMaKCharacter *character_;
  UWBItem *wbItemInstance_;

private:
  template <typename T> T *CreateUI(const FString &path);
};
