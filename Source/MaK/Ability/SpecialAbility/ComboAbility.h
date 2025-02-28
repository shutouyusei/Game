#pragma once

#include "../Ability.h"

#include "ComboAbility.generated.h"

UCLASS(Blueprintable)
class UComboAbility : public UAbility {
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TArray<TSubclassOf<UAbility>> comboAbilities_;
  virtual void DoAbility() override;
  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
private:
  UPROPERTY()
  TArray<UAbility *> abilityInstances_;
  int currentAbilityIndex_ = 0;
};
