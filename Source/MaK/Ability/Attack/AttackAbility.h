#pragma once
#include "../Ability.h"

class UShapeComponent;
class AAttackCollision;
class AActor;
class StatsBase;

class AttackAbility : public Ability {
public:
  AttackAbility(UAnimInstance *animInstance, UAnimMontage *animMontage,
                AAttackCollision *collision, StatsBase *stats);
  ~AttackAbility();
  void DoAbility(FTransform transform) override;
  void OnMontageEnded(UAnimMontage *montage, bool bInterrupted) override;
  void AbilityDelegate(AActor *otherActor);

private:
  StatsBase *stats_;
  AAttackCollision *collision_;
};
