#pragma once
#include "Attack/AttackCollision.h"
#include "CoreMinimal.h"
#include "DamageStruct.h"
#include "UObject/NoExportTypes.h"

#include "Attack.generated.h"

UCLASS()
class UAttack : public UObject {
  GENERATED_BODY()
public:
  void Attack(AAttackCollision *attack_collision, AActor *applyier, FDamageStruct damage);
  void EndAttack(AAttackCollision *attack_collision);
};
