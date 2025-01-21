#pragma once
#include "../Ability.h"

class UShapeComponent;
class AAttackCollision;
class AActor;
class StatsBase;
class UAbilityNotify;

class AttackAbility : public Ability {
public:
  AttackAbility(UAnimInstance *animInstance, UAnimMontage *animMontage,
                AAttackCollision *collision, StatsBase *stats);
  ~AttackAbility();
  void DoAbility(FTransform transform) override;

  //Delegate
  void OnMontageEnded(UAnimMontage *montage, bool bInterrupted) override;

  void OnNotifyBegin();
  void OnNotifyEnd();

private:
  UAbilityNotify *notify_;
  StatsBase *stats_;
  AAttackCollision *collision_;
};
