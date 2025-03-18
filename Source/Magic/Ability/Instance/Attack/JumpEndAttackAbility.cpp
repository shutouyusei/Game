#include "JumpEndAttackAbility.h"
#include "Gameframework/Character.h"
#include "Gameframework/CharacterMovementComponent.h"
#include "Module/Montage/MontagePlayer.h"

void UJumpEndAttackAbility::BeginPlay(TObjectPtr<UAbilityManager> manager) {
  UAbility::BeginPlay(manager);
  character_ = Cast<ACharacter>(manager_->GetOwner());
}
void UJumpEndAttackAbility::Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
  // Endする条件を記述
  bool is_falling = character_->GetCharacterMovement()->IsFalling();
  if (!is_falling && !is_end_) {
    is_end_ = true;
    FOnMontageEnded delegate;
    attack_ability_->AttackWithMontage(delegate, manager_->attack_collision_, manager_->GetOwner());
  }
}

void UJumpEndAttackAbility::DoAbility() {
  UAbility::DoAbility();
  is_end_ = false;
  UAnimInstance *animInstance = GetAnimInstance();
  // モンタージュを再生
  FOnMontageEnded delegate;
  delegate.BindUObject(this, &UJumpEndAttackAbility::OnStartMontageEnded);
  MontagePlayer::PlayMontage(animInstance, start_montage_, delegate);
}

void UJumpEndAttackAbility::OnStartMontageEnded(UAnimMontage *montage, bool interrupted) {
  if (!interrupted) {
    // delegate呼び出す必要なし
    UAnimInstance *animInstance = GetAnimInstance();
    animInstance->Montage_Play(loop_montage_);
  }
}

void UJumpEndAttackAbility::OnAttackEnded(UAnimMontage *montage, bool interrupted){
  if(!interrupted){
    UAbility::EndAbility();
  }
}

UAnimInstance *UJumpEndAttackAbility::GetAnimInstance() {
  return character_->GetMesh()->GetAnimInstance();
}
