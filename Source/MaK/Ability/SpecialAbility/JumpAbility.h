#pragma once
#include "../Ability.h"

#include "JumpAbility.generated.h"

class UAnimInstance;
class UAnimMontage;
class ACharacter;

UCLASS()
class UJumpAbility : public UAbility {
  GENERATED_BODY()
public:
  void BeginPlay(TObjectPtr<UAbilityManager> manager) override;
  void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
  void Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
  //
  void DoAbility() override;

private:
  inline UAnimInstance *GetAnimInstance();
  void OnStartMontageEnded(UAnimMontage *montage, bool interrupted);

private:
  UPROPERTY(EditAnywhere, Category = "Ability")
  TObjectPtr<UAnimMontage> start_montage_;
  UPROPERTY(EditAnywhere, Category = "Ability")
  TObjectPtr<UAnimMontage> loop_montage_;
  UPROPERTY(EditAnywhere, Category = "Ability")
  TSubclassOf<UAbility> attack_ability_class;
  //
  UPROPERTY()
  TObjectPtr<UAbility> attack_ability_;
  UPROPERTY()
  bool is_end_ = false;
  UPROPERTY()
  TObjectPtr<ACharacter> character_;
};
