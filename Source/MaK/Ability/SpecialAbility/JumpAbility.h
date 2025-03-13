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
  UJumpAbility();
  virtual ~UJumpAbility();
  virtual void DoAbility() override;

  virtual void BeginPlay() override;
  virtual void Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
  UAnimInstance *GetAnimInstance();
  void OnStartMontageEnded(UAnimMontage *montage, bool interrupted);
  void OnEndMontageEnded(UAnimMontage *montage, bool interrupted);

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  UAnimMontage *startMontage_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  UAnimMontage *endMontage_;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
  UAnimMontage *loopMontage_;

private:
  UPROPERTY()
  bool isEnd_ = false;
  UPROPERTY()
  TObjectPtr<ACharacter> character_;
};
