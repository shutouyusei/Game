#include "Ability.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

Ability::Ability(UAnimInstance *animInstance, UAnimMontage *animMontage)
    : animInstance_(animInstance), animMontage_(animMontage) {
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

void Ability::OnMontageEnded(UAnimMontage *montage, bool bInterrupted) {
  // Check if the montage is interrupted
  UE_LOG(LogTemp, Warning, TEXT("Montage ended in base"));
}

void Ability::PlayMontage() {
  animInstance_->Montage_Play(animMontage_);
  // NOTE:モンタージュ再生後でしかdelegateの設定ができない！！
  // こんなのしるか

  FOnMontageEnded endDelegate;
  endDelegate.BindRaw(this, &Ability::OnMontageEnded);
  animInstance_->Montage_SetEndDelegate(endDelegate, animMontage_);
}
