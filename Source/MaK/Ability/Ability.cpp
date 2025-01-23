#include "Ability.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Actor.h"

Ability::Ability(UAnimInstance *animInstance, UAnimMontage *animMontage,
                 AActor *owner)
    : owner_(owner), animInstance_(animInstance), animMontage_(animMontage) {
  // Create Object
  // Get notify instance from montage
  for (auto notify : animMontage_->Notifies) {
    if (UAbilityNotify *abilityNotify =
            Cast<UAbilityNotify>(notify.NotifyStateClass)) {
      notifies_.Add(abilityNotify);
    }
  }
}

Ability::~Ability() {
  // Destructor
  // Clear notify
  // TODO:SetAnimNotifyDelegateを現在はアビリティ使用時に割り当て解除をしているが，最初に処理することでも代用できるかも
}

void Ability::DoAbility() {
  // Do ability
  UE_LOG(LogTemp, Warning, TEXT("Do ability in base"));
}

void Ability::SetAnimNotifyDelegate(FName name,
                                    std::function<void()> beginDelegate,
                                    std::function<void()> endDelegate) {
  for (auto notify : notifies_) {
    if (notify->Name == name) {
      notify->SetDelegate(beginDelegate, endDelegate);
    }
  }
}

void Ability::PlayMontage() {
  animInstance_->Montage_Play(animMontage_);
  // NOTE:モンタージュ再生後でしかdelegateの設定ができない！！
  // こんなのしるか

  FOnMontageEnded endDelegate;
  endDelegate.BindRaw(this, &Ability::OnMontageEnded);
  animInstance_->Montage_SetEndDelegate(endDelegate, animMontage_);
}

void Ability::OnMontageEnded(UAnimMontage *montage, bool bInterrupted) {
  // Check if the montage is interrupted
  UE_LOG(LogTemp, Warning, TEXT("Montage ended in base"));
}
