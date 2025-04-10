#pragma once
#include "AnimatedAttack.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "AnimatedAttackFactory.generated.h"

class USkillManager;

UCLASS(Blueprintable)
class UAnimatedAttackFactory : public UObject {
  GENERATED_BODY()
public:
  UAnimatedAttack *Create(USkillManager *manager, UAnimMontage *montage);
private:
  void SetNSAnimatedAttack(UAnimatedAttack *attack_module, AActor *character);
};
