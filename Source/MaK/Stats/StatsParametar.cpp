#include "StatsParameter.h"

StatsParameter::StatsParameter(float parameter)
    : defaultParameter_(parameter) {}

float StatsParameter::GetParameter() {
  return (defaultParameter_ + deviation_) * ratio_;
}

void StatsParameter::SetRatio(float ratio) { ratio_ = ratio; }

float StatsParameter::GetDefaultParameter() { return defaultParameter_; }

void StatsParameter::SetDefaultParameter(float parameter) {
  defaultParameter_ = parameter;
}

void StatsParameter::Increase(float amount) { deviation_ += amount; }

void StatsParameter::Decrease(float amount) { deviation_ -= amount; }
