#include "StatusParameter.h"

UStatusParameter::UStatusParameter() {}
UStatusParameter::~UStatusParameter() {}

float UStatusParameter::Get() {
  return (defaultParameter_ + deviation_) * ratio_;
}
