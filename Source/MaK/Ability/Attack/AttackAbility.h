#pragma once
#include "../AnimAbility.h"
#include "DamageStruct.h"

#include "AttackAbility.generated.h"

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
  void OnAttack(AActor *otherActor);

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability|Attack")
  FDamageStruct damage_;
};
