#pragma once
#include "Animation/AnimNotifies/AnimNotify.h"

#include "CanInputNotify.generated.h"

UCLASS()
class UCanInputNotify : public UAnimNotify {
  GENERATED_BODY()
protected:
  void Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation) override;
};
