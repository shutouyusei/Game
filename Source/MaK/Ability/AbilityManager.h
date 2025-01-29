#pragma once
#include "CoreMinimal.h"

class Ability;

// NOTE: プレイヤー専用のアビリティマネージャー
// アビリティの入力制御
class AbilityManager {
public:
  AbilityManager();
  ~AbilityManager();
  void AddAbility(Ability *ability);
  void SetAbility(int index, Ability *ability);
  void ExecuteAbility(int index);

private:
  TArray<Ability*> abilities_;
  int currentAbilityIndex_ = -1;
};
