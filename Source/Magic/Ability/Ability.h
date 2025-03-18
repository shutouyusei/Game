#pragma once
#include "CoreMinimal.h"
#include "Manager/AbilityManager.h"
#include "UObject/NoExportTypes.h"

#include "Ability.generated.h"

// TODO:たくさんアビリティを作って，ゲームの雰囲気をつかむ
// 空中アビリティを作成する

UCLASS(Blueprintable)
class UAbility : public UObject {
  GENERATED_BODY()
public:
  virtual void BeginPlay(TObjectPtr<UAbilityManager> owner);
  virtual void Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {};
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

  // Don't call directly
  // Call by Ability Manager
  virtual void DoAbility();
  virtual void EndAbility();

protected:
  UPROPERTY()
  TObjectPtr<UAbilityManager> manager_ = nullptr;
};
