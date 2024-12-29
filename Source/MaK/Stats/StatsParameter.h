#pragma once

class StatsParameter {
public:
  float Get();
  void Set(float parameter);
  //
  float GetDefault();
  void SetDefault(float parameter);
  //
  void Increase(float amount);
  void Decrease(float amount);

protected:
  float parameter_;
  float defaultParameter_;
};
