#pragma once
#include "../Ability.h"

class UShapeComponent;
class AAttackCollision;
class AActor;

class AttackAbility : public Ability {
public:
  AttackAbility(UAnimInstance *animInstance, UAnimMontage *animMontage,
                AAttackCollision *collision);
  ~AttackAbility();
  void DoAbility(FTransform transform) override;
  void OnMontageEnded(UAnimMontage *montage, bool bInterrupted) override;
  void AbilityDelegate(AActor *otherActor);
  std::function<void(AActor *)> delegate_;

private:
  AAttackCollision *collision_;
};
