#pragma once
#include "AttackCollision.h"
#include "DamageStruct.h"
// TODO:namespaceにする

class AttackPlayer {
public:
  static void Attack(AAttackCollision *attack_collision, AActor *applyier, FDamageStruct damage);
  static void EndAttack(AAttackCollision *attack_collision);
};
