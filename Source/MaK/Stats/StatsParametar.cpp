#include "StatsParameter.h"

StatsParameter::StatsParameter(float parameter) : defaultParameter_(parameter) {}

float StatsParameter::Get() { return defaultParameter_ * ratio_ + deviation_; }

void StatsParameter::SetRatio(float ratio) { ratio_ = ratio; }

float StatsParameter::GetDefault() { return defaultParameter_; }

void StatsParameter::SetDefault(float parameter) { defaultParameter_ = parameter;}

void StatsParameter::Increase(float amount) { deviation_ += amount; }

void StatsParameter::Decrease(float amount) { deviation_ -= amount; }
