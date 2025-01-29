#pragma once
#include "DamageStruct.h"

class StatsBase;

class Damage {
public:
  static void ApplyDamage(StatsBase *applyier, StatsBase *target,
                          FDamageStruct damage);
};
