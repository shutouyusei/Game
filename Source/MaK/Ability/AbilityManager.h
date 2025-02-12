#pragma once
#include "Ability.h"
#include "Attack/AttackCollision.h"
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

  UFUNCTION(BlueprintCallable, Category = "Ability")
  void SetAbility(int index, TSubclassOf<UAbility> abilityClass);

  UFUNCTION(BlueprintCallable, Category = "Ability")
  void Execute(int index);

  UFUNCTION(BlueprintCallable, Category = "Ability")
  void SetupAbilityManager(AAttackCollision *attackCollision);

  // アビリティからの通知
  void CanInput();
  void CanNextAbility();

  void End();

private:
  virtual void BeginPlay() override;
  void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
  void ExecuteNext();

public:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TArray<TSubclassOf<UAbility>> abilities_;

  UPROPERTY(EditAnywhere, Category = "Ability")
  AAttackCollision *attackCollision_;

private:
  bool canInput_ = true;
  bool canNextAbility_ = true;
  int currentAbilityIndex_ = -1;
  int nextAbilityIndex_ = -1;
};
