#include "Attack.h"

void AttackPlayer::Attack(AAttackCollision *attack_collision, AActor *applyier, FDamageStruct damage) {
  attack_collision->StartAttack(applyier, damage);
}

void AttackPlayer::EndAttack(AAttackCollision *attack_collision) {
  attack_collision->EndAttack();
}
