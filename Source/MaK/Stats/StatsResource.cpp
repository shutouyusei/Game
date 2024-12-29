#include "StatsResource.h"

void StatsResource::SetDeathCallback(void (*deathCallback)()) {
  deathCallback_ = deathCallback;
}

void StatsResource::Heal(float amount) {
  currentParameter_ += amount;
  if (currentParameter_ > parameter_) {
    currentParameter_ = parameter_;
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

float StatsResource::GetCurrent() { return currentParameter_; }
