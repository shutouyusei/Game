#pragma once
#include "CharacterStats.h"
#include "CoreMinimal.h"

class StatsHandler {
public:
  StatsHandler();
  void SetUpStats(/* some save data */);
  // set
  void ChangeMaxStats(const FCharacterStats &stats);
  void ChangeCurrentHP(const float varHP);
  void ChangeCurrentMP(const float varMP);
  // get
  FCharacterStats GetMaxStats() { return MaxStats; };
  float GetCurrentHP() { return CurrentHP; };
  float GetCurrentMP() { return CurrentMP; };

  // test
  void test() { UE_LOG(LogTemp, Warning, TEXT("[StatsHandler]test")); };

private:
  float CurrentHP;
  float CurrentMP;
  FCharacterStats MaxStats;
};
