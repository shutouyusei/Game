#pragma once
#include "Ability.h"
#include "Module/Attack/AttackWithMontage.h"

#include "JumpEndAttackAbility.generated.h"

class UAnimInstance;
class UAnimMontage;
class ACharacter;

UCLASS()
class UJumpEndAttackAbility final : public UAbility {
  GENERATED_BODY()
public:
  void BeginPlay(TObjectPtr<UAbilityManager> manager);
  void Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
  //
  void DoAbility() override;

private:
  inline UAnimInstance *GetAnimInstance();
  void OnStartMontageEnded(UAnimMontage *montage, bool interrupted);
  void OnAttackEnded(UAnimMontage *montage, bool interrupted);

private:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TObjectPtr<UAnimMontage> start_montage_;
  UPROPERTY(EditAnywhere, Category = "Ability")
  TObjectPtr<UAnimMontage> loop_montage_;
  UPROPERTY(EditAnywhere, Category = "Ability")
  TObjectPtr<UAttackWithMontage> attack_ability_;

  //
  UPROPERTY()
  bool is_end_ = false;
  UPROPERTY()
  TObjectPtr<ACharacter> character_;
};
