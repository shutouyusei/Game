#include "MyAbility.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CoreMinimal.h"

MyAbility::MyAbility(AMyCharacter *character) {
  character_ = character;
  // Load Montage
}

MyAbility::~MyAbility() {}

void MyAbility::PlayMontage(UAnimMontage *montage) {
  UAnimInstance *animInstance = character_->GetMesh()->GetAnimInstance();
  animInstance->Montage_Play(montage);
}

void MyAbility::StopMontage(UAnimMontage *montage) {
  UAnimInstance *animInstance = character_->GetMesh()->GetAnimInstance();
  animInstance->Montage_Stop(0.3f, montage);
}
