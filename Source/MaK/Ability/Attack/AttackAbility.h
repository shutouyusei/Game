#pragma once
#include "../AnimAbility.h"
#include "Damage.h"

#include "AttackAbility.generated.h"

class AAttackCollision;
struct FDamageStruct;

UCLASS(Blueprintable)
class UAttackAbility : public UAnimAbility {
  GENERATED_BODY()
public:
  UAttackAbility();
  ~UAttackAbility() = default;
  virtual void DoAbility() override;
  virtual void EndAbility() override;

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  FDamageStruct damage_;

protected:
  AAttackCollision *collision_;
};
