#pragma once

class Ability {

public:
  virtual ~Ability() = default;
  virtual void DoAbility() = 0;
};
