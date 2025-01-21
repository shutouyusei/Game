#pragma once
#include "../Ability.h"
#include "Damage.h"

class UShapeComponent;
class AAttackCollision;
class AActor;
class StatsBase;
class UAbilityNotify;

class AttackAbility : public Ability {
public:
  AttackAbility(UAnimInstance *animInstance, UAnimMontage *animMontage,
                AAttackCollision *collision, StatsBase *stats,
                FDamageStruct damage);
  ~AttackAbility();
  void DoAbility(FTransform transform) override;

  // Delegate
  void OnMontageEnded(UAnimMontage *montage, bool bInterrupted) override;

  void OnNotifyBegin();
  void OnNotifyEnd();

private:
  bool isAttacking_ = false;
  FDamageStruct damage_;
  UAbilityNotify *notify_;
  StatsBase *stats_;
  AAttackCollision *collision_;
};
