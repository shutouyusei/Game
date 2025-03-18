#include "SingleAttackAbility.h"

void USingleAttackAbility::DoAbility() {
  UAbility::DoAbility();
  if (attack_ability != nullptr) {
    FOnMontageEnded delegate;
    delegate.BindUObject(this, &USingleAttackAbility::OnMontageEnded);
    attack_ability->AttackWithMontage(delegate, manager_->attack_collision_, manager_->GetOwner());
  }
}

void USingleAttackAbility::OnMontageEnded(UAnimMontage *montage, bool interrupted) {
  if (!interrupted) {
    UAbility::EndAbility();
  }
}
