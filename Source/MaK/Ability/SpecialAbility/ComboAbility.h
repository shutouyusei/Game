#pragma once
#include "../Ability.h"

#include "ComboAbility.generated.h"

UCLASS(Blueprintable)
class UComboAbility : public UAbility {
  GENERATED_BODY()

public:
  void BeginPlay(TObjectPtr<UAbilityManager> manager) override;
  void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
  void DoAbility() override;

private:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TArray<TSubclassOf<UAbility>> combo_abilities_;
  UPROPERTY()
  TArray<TObjectPtr<UAbility>> ability_instances_;
  int combo_index_ = 0;
};
