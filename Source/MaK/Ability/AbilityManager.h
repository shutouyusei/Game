#pragma once
#include "Attack/AttackCollision.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "AbilityManager.generated.h"

UENUM(BlueprintType)
enum class EAbilityFlag : uint8 {
  None = 0,
  CanNextAbility = 1,
  CanInput = 2,
  Playing = 3,
};

class UAbility;
// プレイヤー専用のアビリティマネージャー
// アビリティの入力制御
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UAbilityManager final : public UActorComponent {
  GENERATED_BODY()
public:
  UAbilityManager();
  ~UAbilityManager() {};
  // BP Begin Play
  UFUNCTION(BlueprintCallable, Category = "Ability")
  void SetupAbilityManager(AAttackCollision *attack_collision);

  // set and change ability
  UFUNCTION(BlueprintCallable, Category = "Ability")
  void SetAbility(int index, UAbility *ability);

  // execute ability
  UFUNCTION(BlueprintCallable, Category = "Ability")
  void Execute(int index);

  void EndCurrentAbility();

  // アビリティからの通知
  void SetAbilityFlag(EAbilityFlag flag);
  void ExecuteNext();

private:
  void BeginPlay() override;
  void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
  void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
  //
  void ExecuteAbility(int index);

public:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TArray<TSubclassOf<UAbility>> ability_classes_;
  UPROPERTY()
  AAttackCollision *attack_collision_;

private:
  UPROPERTY()
  TArray<UAbility *> ability_instances_;
  UPROPERTY()
  EAbilityFlag ability_flag_ = EAbilityFlag::None;
  // - 1  = Null Ability
  UPROPERTY()
  int current_ability_index_ = -1;
  UPROPERTY()
  int next_ability_index_ = -1;
};
