#pragma once
#include "Ability.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "AbilityManager.generated.h"

// NOTE: プレイヤー専用のアビリティマネージャー
// アビリティの入力制御
UCLASS()
class UAbilityManager : public UActorComponent {
  GENERATED_BODY()
public:
  UAbilityManager();
  ~UAbilityManager();

  void AddAbility(Ability *ability);
  void SetAbility(int index, Ability *ability);
  void ExecuteAbility(int index);

private:
  TArray<Ability *> abilities_;
  int currentAbilityIndex_ = -1;
};
