#pragma once

class StatsBase;

class Damage {
public:
  static void ApplyDamage(StatsBase &applyier, StatsBase &target, float damage);
};
