#pragma once
#include "Animation/AnimNotifies/AnimNotify.h"

#include "SkillNotify.generated.h"

DECLARE_DELEGATE(FSkillEffect);

UCLASS()
class USkillNotify : public UAnimNotify {
  GENERATED_BODY()
protected:
  void Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation) override;

public:
  FSkillEffect skill_effect_;
};
