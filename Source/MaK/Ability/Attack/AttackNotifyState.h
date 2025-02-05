#pragma once
#include "Animation/AnimNotifies/AnimNotifyState.h"

#include "AttackNotifyState.generated.h"

UCLASS()
class UAttackNotifyState : public UAnimNotifyState {
  GENERATED_BODY()
public:
  virtual void NotifyBegin(USkeletalMeshComponent *MeshComp,
                           UAnimSequenceBase *Animation,
                           float TotalDuration) override;
  virtual void NotifyEnd(USkeletalMeshComponent *MeshComp,
                         UAnimSequenceBase *Animation) override;
};
