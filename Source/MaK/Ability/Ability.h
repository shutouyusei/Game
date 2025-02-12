#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Ability.generated.h"

class UAbilityManager;

UCLASS(Blueprintable)
class UAbility : public UObject {
  GENERATED_BODY()
public:
  UAbility();
  virtual ~UAbility() = default;

  // NOTE: call by Ability Manager when set ability
  // XXX:この方法だとEnemyとプレイヤーの区別ができない
  // アビリティインスタンスは一つしか存在しない
  void SetOwner(UAbilityManager *owner);

  // NOTE :Don't call directly
  // Call by Ability Manager
  virtual void DoAbility();
  virtual void EndAbility();

protected:
  UAbilityManager *owner_;
};
