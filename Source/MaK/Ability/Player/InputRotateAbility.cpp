#include "InputRotateAbility.h"
#include "Math/UnrealMathUtility.h"
#include "MyCharacter.h"

void UInputRotateAbility::BeginPlay() {
  // Create the ability
  Ability_ = NewObject<UAbility>(this, InputAbility_);
  Ability_->SetOwner(owner_);
  Ability_->BeginPlay();
}

void UInputRotateAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Ability_->EndPlay(EndPlayReason);
  Ability_->ConditionalBeginDestroy();
}

void UInputRotateAbility::DoAbility() {
  // Input情報から向きを決める
  AMyCharacter *character = Cast<AMyCharacter>(owner_->GetOwner());
  if (character == nullptr)
    return;
  // Set the angle
  FVector2D input = character->GetMoveInputValue();
  if (input.Size() > 0.1f) {
    float angle = CalcuateMoveRadians(character, input);
    character->SetActorRotation(FRotator(0.0f, angle, 0.0f));
  }
  // DoAbility
  Ability_->DoAbility();
}

void UInputRotateAbility::EndAbility() { Ability_->EndAbility(); }

// NOTE: 入力方向への回転をする
// この方が操作が直感的
float UInputRotateAbility::CalcuateMoveRadians(AMyCharacter *character,
                                               FVector2D input) {
  // Calculate the move direction
  input = {-input.X, input.Y};
  // Get the camera forward vector
  FVector2D cameraForward = character->GetCameraForwardVector();
  // calculate
  FVector2D moveDirection = input.GetRotated(
      -FMath::RadiansToDegrees(FMath::Atan2(cameraForward.X, cameraForward.Y)));
  // Check actor forward and move direction
  return FMath::RadiansToDegrees(
      FMath::Atan2(moveDirection.Y, moveDirection.X));
}
