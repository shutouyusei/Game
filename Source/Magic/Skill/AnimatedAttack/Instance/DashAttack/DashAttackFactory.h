#pragma once
#include "../../../SkillFactory.h"

#include "DashAttackFactory.generated.h"

struct FAnimNotifyEvent;

UCLASS()
class UDashAttackFactory : public USkillFactory {
  GENERATED_BODY()
public:
  USkill *Create(USkillManager *manager) override;

private:
  void DisableInvincibleNotify(TArray<FAnimNotifyEvent> Notifies);

private:
  UPROPERTY(EditAnywhere)
  TObjectPtr<UAnimMontage> montage_;
};
