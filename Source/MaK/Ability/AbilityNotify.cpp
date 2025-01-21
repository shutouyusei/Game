#include "AbilityNotify.h"
#include "Animation/AnimInstance.h"

UAbilityNotify::UAbilityNotify() {
  // Constructor
}

UAbilityNotify::~UAbilityNotify() {
  // Destructor
}


void UAbilityNotify::NotifyBegin(USkeletalMeshComponent *MeshComp,
                                 UAnimSequenceBase *Animation,
                                 float TotalDuration) {
  // Check if the notify is beginning
  if(beginDelegate_ != nullptr)
    beginDelegate_();
}

void UAbilityNotify::NotifyEnd(USkeletalMeshComponent *MeshComp,
                               UAnimSequenceBase *Animation) {
  // Check if the notify is ending
  if(endDelegate_ != nullptr)
    endDelegate_();
}


void UAbilityNotify::SetDelegate(std::function<void()> beginDelegate,
                                 std::function<void()> endDelegate) {
  // Set the delegate
  beginDelegate_ = beginDelegate;
  endDelegate_ = endDelegate;
}
