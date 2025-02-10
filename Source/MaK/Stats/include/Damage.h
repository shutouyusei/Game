#pragma once
#include "DamageStruct.h"

class UStatsBase;

class Damage {
public:
  static void ApplyDamage(UStatsBase *applyier, UStatsBase *target,
                          FDamageStruct damage);
};
