#pragma once
#include "../Ability.h"

#include "InputAbility.generated.h"

UCLASS(Blueprintable)
class UInputAbility : public UAbility {
  GENERATED_BODY()
public:
  virtual void DoAbility() override;

protected:
  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TSubclassOf<UAbility> InputAbility_;

private:
  UPROPERTY()
  UAbility *Ability_;
};
