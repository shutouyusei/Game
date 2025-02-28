#pragma once
#include "Animation/AnimNotifies/AnimNotify.h"

#include "CanNextAbilityNotify.generated.h"

UCLASS()
class UCanNextAbilityNotify : public UAnimNotify {
  GENERATED_BODY()
protected:
  void Notify(USkeletalMeshComponent *MeshComp,
              UAnimSequenceBase *Animation) override;
};
