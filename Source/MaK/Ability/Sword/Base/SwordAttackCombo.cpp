#include "SwordAttackCombo.h"
#include "SwordAttack1.h"
#include "SwordAttack2.h"
#include "SwordAttack3.h"
#include "SwordAttack4.h"

SwordAttackCombo::SwordAttackCombo(UAbilityManager *owner,
                                   UAnimInstance *animInstance,
                                   AAttackCollision *collision)
    : Ability(owner) {
  // Set up the attack ability
  comboAbilities_[0] = new SwordAttack1(owner, animInstance, collision);
  comboAbilities_[1] = new SwordAttack2(owner, animInstance, collision);
  comboAbilities_[2] = new SwordAttack3(owner, animInstance, collision);
  comboAbilities_[3] = new SwordAttack4(owner, animInstance, collision);
}

SwordAttackCombo::~SwordAttackCombo() {
  for (int i = 0; i < 4; i++) {
    delete comboAbilities_[i];
  }
}

void SwordAttackCombo::DoAbility() {
  // TODO:コンボがつながるかつながらないかの判定
  comboCount_ = (comboCount_ + 1) % 4;
  comboAbilities_[comboCount_]->DoAbility();
}

void SwordAttackCombo::EndAbility() {
  comboAbilities_[comboCount_]->EndAbility();
}
