#pragma once
#include "CoreMinimal.h"

class Ability;

// NOTE: プレイヤー専用のアビリティマネージャー
// アビリティの入力制御
class AbilityManager {
public:
  AbilityManager(TArray<Ability *> abilities);
  ~AbilityManager();
  void ExecuteAbility(int index);

private:
  void EndAbility();
  bool canInput_ = true;
  bool isExecuting_ = false;
  TArray<Ability *> abilities_;
  int currentAbilityIndex_ = -1;
  int nextAbilityIndex_ = -1;
};
