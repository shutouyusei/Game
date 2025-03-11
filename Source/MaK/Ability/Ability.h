#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Ability.generated.h"

class UAbilityManager;
// TODO:たくさんアビリティを作って，ゲームの雰囲気をつかむ
// 空中アビリティを作成する

UCLASS(Blueprintable)
class UAbility : public UObject {
    GENERATED_BODY()
  public:
    UAbility();
    virtual ~UAbility() = default;

    // NOTE: call by Ability Manager when set ability
    void SetOwner(UAbilityManager *owner);
    virtual void BeginPlay();
    virtual void Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

    // NOTE :Don't call directly
    // Call by Ability Manager
    virtual void DoAbility();
    virtual void EndAbility();

  protected:
    UPROPERTY()
    UAbilityManager *owner_;
};
