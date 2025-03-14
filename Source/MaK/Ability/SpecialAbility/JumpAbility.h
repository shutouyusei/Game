#pragma once
#include "../Ability.h"
#include "../Attack/AttackAbility.h"

#include "JumpAbility.generated.h"

class UAnimInstance;
class UAnimMontage;
class ACharacter;

UCLASS()
class UJumpAbility : public UAbility {
  GENERATED_BODY()
public:
  UJumpAbility();
  virtual ~UJumpAbility();
  virtual void DoAbility() override;

  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
  virtual void Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
  UAnimInstance *GetAnimInstance();
  void OnStartMontageEnded(UAnimMontage *montage, bool interrupted);
  void OnEndMontageEnded(UAnimMontage *montage, bool interrupted);

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  TObjectPtr<UAnimMontage> StartMontage_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  TObjectPtr<UAnimMontage> LoopMontage_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  TSubclassOf<UAbility> AttackAbilityClass_;

private:
  UPROPERTY()
  TWeakObjectPtr<UAbility> AttackAbility_;
  UPROPERTY()
  bool isEnd_ = false;
  UPROPERTY()
  TObjectPtr<ACharacter> character_;
};
