#include "StatsResource.h"

void StatsResource::SetDeathCallback(void (*deathCallback)()) {
  deathCallback_ = deathCallback;
}

void StatsResource::Heal(float amount) {
  currentParameter_ += amount;
  float parameter = Get();
  if (currentParameter_ > parameter) {
    currentParameter_ = parameter;
  }
}

void StatsResource::Damage(float amount) {
  currentParameter_ -= amount;
  if (currentParameter_ < 0) {
    currentParameter_ = 0;
    if (deathCallback_ != nullptr) {
      deathCallback_();
    }
  }
}

void StatsResource::Decrease(float amount) {
  StatsParameter::Decrease(amount);
  float parameter = Get();
  if (currentParameter_ > parameter) {
    currentParameter_ = parameter;
  }
}

float StatsResource::GetCurrent() { return currentParameter_; }

void StatsResource::SetCurrent(float amount) {
  currentParameter_ = amount;
}
