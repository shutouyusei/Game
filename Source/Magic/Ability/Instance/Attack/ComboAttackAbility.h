#pragma once
#include "Ability.h"
#include "DamageStruct.h"
#include "Module/Attack/AttackWithMontage.h"

#include "ComboAttackAbility.generated.h"

UCLASS()
class UComboAttackAbility final : public UAbility {
  GENERATED_BODY()
public:
  void DoAbility() override;

private:
  void OnMontageEnded(UAnimMontage *montage, bool interrupted);
  UPROPERTY(Instanced, EditAnywhere, Category = "Default")
  TArray<TObjectPtr<UAttackWithMontage>> attack_abilities_;
  UPROPERTY()
  int8 combo_index_ = 0;
};
