#include "AttackAbility.h"
#include "Components/ShapeComponent.h"

AttackAbility::AttackAbility(UAnimInstance *animInstance,
                             UAnimMontage *animMontage,UShapeComponent  *collision)
    : Ability(animInstance, animMontage), collision_(collision) {}

void AttackAbility::DoAbility(FTransform transform) {
  // Attack the target
  animInstance_->Montage_Play(animMontage_);
  // Check if the collision is valid
  // TODO:damage
}
