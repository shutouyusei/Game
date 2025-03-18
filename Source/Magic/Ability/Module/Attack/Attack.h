#pragma once
#include "AttackCollision.h"
#include "DamageStruct.h"

class AttackPlayer {
public:
  static void Attack(AAttackCollision *attack_collision, AActor *applyier, FDamageStruct damage);
  static void EndAttack(AAttackCollision *attack_collision);
};
