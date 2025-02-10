#include "StatsParameter.h"

UStatsParameter::UStatsParameter() {}

float UStatsParameter::Get() {
  return (defaultParameter_ + deviation_) * ratio_;
}
