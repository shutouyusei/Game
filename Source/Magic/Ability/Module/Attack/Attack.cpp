#include "Attack.h"

void UAttack::Attack(AAttackCollision *attack_collision, AActor *applyier, FDamageStruct damage) {
  attack_collision->StartAttack(applyier, damage);
}

void UAttack::EndAttack(AAttackCollision *attack_collision) {
  attack_collision->EndAttack();
}
