#include "SkillNotify.h"

void USkillNotify::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation) {
  skill_effect_.ExecuteIfBound();
}
