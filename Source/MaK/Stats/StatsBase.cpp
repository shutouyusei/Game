#include "StatsBase.h"

StatsBase::StatsBase() {
  HP_.SetDeathCallback([]() {
    // Do something when HP reaches 0
  });
}

StatsBase::~StatsBase() {
}
