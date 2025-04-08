#pragma once
#include "Animation/AnimNotifies/AnimNotify.h"

#include "EndSkillNotify.generated.h"

UCLASS()
class UEndSkillNotify : public UAnimNotify {
  GENERATED_BODY()
protected:
  void Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation) override;
};
