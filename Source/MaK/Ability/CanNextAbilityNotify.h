#pragma once
#include "Animation/AnimNotifies/AnimNotify.h"

#include "CanNextAbilityNotify.generated.h"

UCLASS()
class UCanNextAbilityNotify : public UAnimNotify {
  GENERATED_BODY()
public:
protected:
  void Notify(USkeletalMeshComponent *MeshComp,
              UAnimSequenceBase *Animation) override;
};
