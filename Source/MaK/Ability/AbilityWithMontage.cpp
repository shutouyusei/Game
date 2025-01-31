#include "AbilityWithMontage.h"
#include "Ability.h"
#include "AbilityNotify.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CoreMinimal.h"

AbilityWithMontage::AbilityWithMontage(UAbilityManager *owner,
                                       UAnimInstance *animInstance_)
    : Ability(owner), animInstance_(animInstance_) {}

AbilityWithMontage::~AbilityWithMontage() {
  // Destructor
  // Clear notify
  for (auto notify : notifies_) {
    notify->SetDelegate(nullptr, nullptr);
  }
}

void AbilityWithMontage::PlayMontage() {
  animInstance_->Montage_Play(animMontage_);

  // NOTE:モンタージュ再生後でしかdelegateの設定ができない！！
  // こんなのしるか
}

void AbilityWithMontage::StopMontage() {
  animInstance_->Montage_Stop(0.0f, animMontage_);
}

void AbilityWithMontage::SetAnimNotifyDelegate(
    FName name, std::function<void()> beginDelegate,
    std::function<void()> endDelegate) {
  for (auto notify : notifies_) {
    if (notify->Name == name) {
      notify->SetDelegate(beginDelegate, endDelegate);
    }
  }
}

// NOTE: call after setting animMontage_
// and in the constructor of the child class
void AbilityWithMontage::SetUpAbilityWithMontage() {
  // Get UAbilityNotify
  for (auto notify : animMontage_->Notifies) {
    if (UAbilityNotify *abilityNotify =
            Cast<UAbilityNotify>(notify.NotifyStateClass)) {
      notifies_.Add(abilityNotify);
    }
  }

  // TODO:先行入力機能いりそうだったらつける
  SetAnimNotifyDelegate(
      TEXT("Ability"), [this]() { isExecuting_ = true; },
      [this]() { isExecuting_ = false; });
}
