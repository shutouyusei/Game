#include "StatsParameter.h"

float StatsParameter::Get() { return parameter_; }

float StatsParameter::GetDefault() { return defaultParameter_; }

void StatsParameter::Set(float parameter) { parameter_ = parameter; }

void StatsParameter::SetDefault(float parameter) {
  defaultParameter_ = parameter;
}

void StatsParameter::Increase(float amount) { parameter_ += amount; }

void StatsParameter::Decrease(float amount) { parameter_ -= amount; }
