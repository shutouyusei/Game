#pragma once
#include "Ability.h"
#include "DamageStruct.h"
#include "Module/Attack/AttackWithMontage.h"

#include "SingleAttackAbility.generated.h"

UCLASS()
class USingleAttackAbility final : public UAbility {
  GENERATED_BODY()
public:
  void DoAbility() override;

private:
  void OnMontageEnded(UAnimMontage *montage, bool interrupted);
  UPROPERTY(EditAnywhere, Category = "Default")
  TObjectPtr<UAttackWithMontage> attack_ability;
};
