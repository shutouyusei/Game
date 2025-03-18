#pragma once
#include "CoreMinimal.h"
#include "Manager/AbilityManager.h"
#include "UObject/NoExportTypes.h"

#include "AbilityModifier.generated.h"

// TODO:たくさんアビリティを作って，ゲームの雰囲気をつかむ
// 空中アビリティを作成する

UCLASS(Blueprintable)
class UAbilityModifier : public UObject {
  GENERATED_BODY()
public:
  virtual void AbiltiyMod(UAbilityManager *manager);
};
