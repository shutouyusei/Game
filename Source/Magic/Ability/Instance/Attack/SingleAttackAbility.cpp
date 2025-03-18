#include "SingleAttackAbility.h"

void USingleAttackAbility::DoAbility() {
  UAbility::DoAbility();
  if (attack_ability != nullptr) {
    FOnMontageEnded delegate;
    attack_ability->AttackWithMontage(delegate, manager_->attack_collision_, manager_->GetOwner());
  }
}

void USingleAttackAbility::OnMontageEnded(UAnimMontage *montage, bool interrupted) {
  UAbility::EndAbility();
}
