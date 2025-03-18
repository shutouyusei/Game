#include "JumpAbility.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Gameframework/Character.h"
#include "Gameframework/CharacterMovementComponent.h"

void UJumpAbility::BeginPlay(TObjectPtr<UAbilityManager> manager) {
  Super::BeginPlay(manager);
  character_ = Cast<ACharacter>(manager_->GetOwner());
  if (attack_ability_class == nullptr) {
    UE_LOG(LogTemp, Error, TEXT("UJumpAbility::BeginPlay: attack_ability_class is nullptr"));
    return;
  }
  attack_ability_ = NewObject<UAbility>(this, attack_ability_class);
  attack_ability_->BeginPlay(manager);
}

void UJumpAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  attack_ability_->EndPlay(EndPlayReason);
  attack_ability_->ConditionalBeginDestroy();
}

void UJumpAbility::Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
  // Endする条件を記述
  bool is_falling = character_->GetCharacterMovement()->IsFalling();
  if (!is_falling && !is_end_) {
    is_end_ = true;
    attack_ability_->DoAbility();
  }
}

void UJumpAbility::DoAbility() {
  is_end_ = false;
  UAnimInstance *animInstance = GetAnimInstance();
  // モンタージュを再生
  animInstance->Montage_Play(start_montage_);
  FOnMontageEnded del;
  del.BindUObject(this, &UJumpAbility::OnStartMontageEnded);
  animInstance->Montage_SetEndDelegate(del, start_montage_);
}

void UJumpAbility::OnStartMontageEnded(UAnimMontage *montage, bool interrupted) {
  if (!interrupted) {
    UAnimInstance *animInstance = GetAnimInstance();
    animInstance->Montage_Play(loop_montage_);
  }
}

UAnimInstance *UJumpAbility::GetAnimInstance() {
  return character_->GetMesh()->GetAnimInstance();
}
