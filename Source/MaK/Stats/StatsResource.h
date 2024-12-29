#pragma once
#include "StatsParameter.h"

class StatsResource : public StatsParameter {
public:
  void SetDeathCallback(void (*deathCallback)());
  //
  void Heal(float amount);
  void Damage(float amount);
  //
  float GetCurrent();

private:
  float currentParameter_;
  void (*deathCallback_)();
};
