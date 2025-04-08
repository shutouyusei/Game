#include "EndSkillNotify.h"
#include "../SkillManager.h"
#include "GameFramework/Actor.h"

void UEndSkillNotify::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation) {
  // Check if the notify is called
  // Get the owner of the mesh
  AActor *owner = MeshComp->GetOwner();
  if (owner == nullptr) {
    return;
  }
  // Get Ability Manager
  USkillManager *manager = owner->FindComponentByClass<USkillManager>();
  if (manager == nullptr) {
    return;
  }
  // TODO:スキルマネージャーで状態遷移ができているか確認
  //  Set the ability manager to be able to input
  manager->execution_manager_->SetSkillFlag(ESkillFlag::None);
}
