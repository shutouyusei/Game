#include "StatsResource.h"

void StatsResource::IncreaseResource(float amount) {
  resource += amount;
  if (MaxResource < resource) {
    resource = MaxResource;
  }
}

void StatsResource::DecreaseResource(float amount) {
  resource -= amount;
  if (resource < 0.0) {
    // NOTE:dead
    resource = 0.0;
    if (deathCallback != nullptr) {
      deathCallback();
    }
  }
}
