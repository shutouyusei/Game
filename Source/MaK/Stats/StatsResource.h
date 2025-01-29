#pragma once
#include "StatsParameter.h"
#include <functional>

class StatsResource : public StatsParameter {
public:
  ~StatsResource() = default;
  void SetDeathCallback(std::function<void()> deathCallback);
  //
  void Heal(float amount);
  void Damage(float amount);
  //
  void SetCurrentParameter(float amount);
  float GetCurrentParameter();

  void Decrease(float amount) override;

private:
  float currentParameter_;
  std::function<void()> deathCallback_;
};
