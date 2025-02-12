#pragma once
#include "../AnimAbility.h"
#include "DamageStruct.h"

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

private:
  void AttachAttackCollision();

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability|Attack")
  FDamageStruct damage_;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability|Attack")
  FName collisionSocketName_;
};
