#pragma once
#include "Animation/AnimNotifies/AnimNotifyState.h"

#include "NSInvincible.generated.h"

UCLASS()
class UNSInvincible : public UAnimNotifyState {
  GENERATED_BODY()
public:
  void NotifyBegin(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, float TotalDuration) override;
  void NotifyEnd(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation) override;

public:
  UPROPERTY()
  bool bCanActive = true;
};
