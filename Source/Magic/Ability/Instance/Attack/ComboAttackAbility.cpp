#include "ComboAttackAbility.h"

void UComboAttackAbility::DoAbility() {
  UAbility::DoAbility();
  if (attack_abilities_.Num() == 0) {
    return;
  }
  UAttackWithMontage *attack_ability = attack_abilities_[combo_index_];
  if (attack_ability != nullptr) {
    FOnMontageEnded delegate;
    delegate.BindUObject(this, &UComboAttackAbility::OnMontageEnded);
    attack_ability->AttackWithMontage(delegate, manager_->attack_collision_, manager_->GetOwner());
  }
  combo_index_ = (combo_index_ + 1) % attack_abilities_.Num();
}

void UComboAttackAbility::OnMontageEnded(UAnimMontage *montage, bool interrupted) {
  if (!interrupted) {
    UAbility::EndAbility();
  }
}
