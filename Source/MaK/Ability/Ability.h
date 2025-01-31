#pragma once
#include "CoreMinimal.h"

class UAbilityManager;

class Ability {
public:
  Ability(UAbilityManager *owner);
  virtual ~Ability() = default;

  virtual void DoAbility() = 0;
  virtual void EndAbility() = 0;
  virtual bool IsExecuting() { return isExecuting_; }

protected:
  bool isExecuting_ = false;

protected:
  UAbilityManager *owner_;
};
