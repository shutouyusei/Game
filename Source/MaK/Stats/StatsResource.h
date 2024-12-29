#pragma once
#include "StatsParameter.h"

class StatsResource : public StatsParameter {
public:
  void SetDeathCallback(void (*deathCallback)());
  //
  void Heal(float amount);
  void Damage(float amount);
  //
  void SetCurrent(float amount);
  float GetCurrent();

  //
  void Decrease(float amount) override;

private:
  float currentParameter_;
  void (*deathCallback_)();
};
