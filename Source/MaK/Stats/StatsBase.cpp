#include "StatsBase.h"
#include "StatsResource.h"

StatsBase::StatsBase(void (*deathCallback)()) {
  if (deathCallback != nullptr) {
    HP_ = new StatsResource(deathCallback);
  }else{
    HP_ = new StatsResource();
  }
    MP_ = new StatsResource();
}

StatsBase::~StatsBase() {
  delete HP_;
  delete MP_;
}
