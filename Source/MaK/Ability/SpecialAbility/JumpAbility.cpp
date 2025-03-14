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
  AttackAbility_ = NewObject<UAbility>(this, AttackAbilityClass_);
  AttackAbility_->SetManager(manager_);
  AttackAbility_->BeginPlay();
}

void UJumpAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  AttackAbility_->EndPlay(EndPlayReason);
  AttackAbility_->ConditionalBeginDestroy();
}

void UJumpAbility::Tick(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
  // Endする条件を記述
  bool isFalling = character_->GetCharacterMovement()->IsFalling();
  if (!isFalling && !isEnd_) {
    isEnd_ = true;
    AttackAbility_->DoAbility();
  }
}

void UJumpAbility::DoAbility() {
  isEnd_ = false;
  UAnimInstance *animInstance = GetAnimInstance();
  // モンタージュを再生
  animInstance->Montage_Play(StartMontage_);
  FOnMontageEnded del;
  del.BindUObject(this, &UJumpAbility::OnStartMontageEnded);
  animInstance->Montage_SetEndDelegate(del, StartMontage_);
}

void UJumpAbility::OnStartMontageEnded(UAnimMontage *montage, bool interrupted) {
  if (!interrupted) {
    UE_LOG(LogTemp, Warning, TEXT("OnStartMontageEnded"))
    UAnimInstance *animInstance = GetAnimInstance();
    animInstance->Montage_Play(LoopMontage_);
  }
}

UAnimInstance *UJumpAbility::GetAnimInstance() {
  return character_->GetMesh()->GetAnimInstance();
}
