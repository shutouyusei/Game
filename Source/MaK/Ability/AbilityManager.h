#pragma once
#include "Ability.h"
#include "Attack/AttackCollision.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "AbilityManager.generated.h"

// NOTE: プレイヤー専用のアビリティマネージャー
// アビリティの入力制御
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UAbilityManager : public UActorComponent {
  GENERATED_BODY()
public:
  UAbilityManager();
  ~UAbilityManager();

  UFUNCTION(BlueprintCallable, Category = "Ability")
  void SetAbility(int index, UAbility *abilityClass);

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
  virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
  void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
  void ExecuteNext();

public:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TArray<TSubclassOf<UAbility>> abilities_;

  UPROPERTY()
  AAttackCollision *attackCollision_;

protected:
  UPROPERTY()
  TArray<UAbility *> abilityInstances_;

private:
  UPROPERTY()
  bool canInput_ = true;
  UPROPERTY()
  bool canNextAbility_ = true;
  UPROPERTY()
  int currentAbilityIndex_ = -1;
  UPROPERTY()
  int nextAbilityIndex_ = -1;
};
