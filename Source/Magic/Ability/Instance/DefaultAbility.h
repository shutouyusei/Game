#pragma once
#include "Ability.h"

#include "DefaultAbility.generated.h"

UCLASS()
class UDefaultAbility final : public UAbility {
  GENERATED_BODY()
public:
  void DoAbility() override;
};
