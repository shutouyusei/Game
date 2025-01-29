#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class Ability {
public:
  Ability(AActor *owner) : owner_(owner) {}
  virtual ~Ability() = default;

  virtual void DoAbility() = 0;
  virtual void EndAbility() = 0;
  virtual bool IsExecuting() { return isExecuting_; }

protected:
  bool isExecuting_ = false;

protected:
  AActor *owner_;
};
