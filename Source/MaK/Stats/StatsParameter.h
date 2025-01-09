#pragma once

class StatsParameter {
public:
  StatsParameter(float parametor = 0.0f);
  //
  float GetParameter();
  //
  float GetDefaultParameter();
  void SetDefaultParameter(float parameter);

  // change stats
  void Increase(float amount);
  virtual void Decrease(float amount);

  void SetRatio(float ratio);

protected:
  float defaultParameter_;
  float ratio_ = 1.0f;
  float deviation_ = 0.0f;
};
