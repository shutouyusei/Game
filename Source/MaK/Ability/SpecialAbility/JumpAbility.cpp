#include "JumpAbility.h"
#include "AbilityManager.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CoreMinimal.h"
#include "Gameframework/Character.h"

UJumpAbility::UJumpAbility() : UAbility() {}

UJumpAbility::~UJumpAbility() {}
// TODO:攻撃アビリティに適応しないといけない

void UJumpAbility::BeginPlay() {
  character_ = Cast<ACharacter>(manager_->GetOwner());
}

void UJumpAbility::Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
  // Endする条件を記述
  bool isFalling = character_->GetCharacterMovement()->IsFalling();
  if (!isFalling && !isEnd_) {
    isEnd_ = true;
    UAnimInstance *animInstance = GetAnimInstance();
    animInstance->Montage_Play(endMontage_);
    FOnMontageEnded del;
    del.BindUObject(this, &UJumpAbility::OnEndMontageEnded);
    animInstance->Montage_SetEndDelegate(del, endMontage_);
  }
}

void UJumpAbility::DoAbility() {
  UAnimInstance *animInstance = GetAnimInstance();
  // モンタージュを再生
  animInstance->Montage_Play(startMontage_);
  FOnMontageEnded del;
  del.BindUObject(this, &UJumpAbility::OnStartMontageEnded);
  animInstance->Montage_SetEndDelegate(del, startMontage_);
}

void UJumpAbility::OnStartMontageEnded(UAnimMontage *montage, bool interrupted) {
  if (!interrupted) {
    UE_LOG(LogTemp, Warning, TEXT("OnStartMontageEnded"))
    UAnimInstance *animInstance = GetAnimInstance();
    animInstance->Montage_Play(loopMontage_);
  }
}

void UJumpAbility::OnEndMontageEnded(UAnimMontage *montage, bool interrupted) {
  isEnd_ = false;
  EndAbility();
}

UAnimInstance *UJumpAbility::GetAnimInstance() {
  return character_->GetMesh()->GetAnimInstance();
}
