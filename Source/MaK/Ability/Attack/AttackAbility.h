#pragma once
#include "../Ability.h"
#include "Damage.h"

class UShapeComponent;
class AAttackCollision;
class StatsBase;
class UAbilityNotify;

class AttackAbility : public Ability {
public:
  AttackAbility(UAnimInstance *animInstance, UAnimMontage *animMontage,
                AActor *owner, AAttackCollision *collisionm,
                FDamageStruct damage);

  ~AttackAbility();
  void DoAbility() override;

  // Delegate
  void OnMontageEnded(UAnimMontage *montage, bool bInterrupted) override;

  void OnNotifyBegin();
  void OnNotifyEnd();

private:
  FDamageStruct damage_;
  UAbilityNotify *notify_;
  AAttackCollision *collision_;
};
