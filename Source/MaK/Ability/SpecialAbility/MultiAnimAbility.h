#pragma once
#include "Ability.h"

#include "MultiAnimAbility.generated.h"

class UAnimInstance;
class UAnimMontage;

UCLASS()
class UMultiAnimAbility : public UAbility {
  GENERATED_BODY()
public:
  UMultiAnimAbility();
  virtual ~UMultiAnimAbility();
  virtual void DoAbility() override;
  //
  UFUNCTION(BlueprintImplementableEvent, Category = "Ability")
  bool PlayEndAbility();

protected:
  virtual void Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
  void PlayMontage(UAnimMontage *montage);

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
};
