#include "InputRotateAbility.h"
#include "Math/UnrealMathUtility.h"
#include "Math/Vector2D.h"
#include "MyCharacter.h"

void UInputRotateAbility::BeginPlay(TObjectPtr<UAbilityManager> manager) {
  Super::BeginPlay(manager);
  // Create the ability
  if (input_ability_ == nullptr) {
    UE_LOG(LogTemp, Error, TEXT("UInputComboAbility::BeginPlay: input_ability_ is nullptr"));
    return;
  }
  ability_ = NewObject<UAbility>(this, input_ability_);
  ability_->BeginPlay(manager);
}

void UInputRotateAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  ability_->EndPlay(EndPlayReason);
  ability_->ConditionalBeginDestroy();
}

void UInputRotateAbility::DoAbility() {
  // Input情報から向きを決める
  AMyCharacter *character = Cast<AMyCharacter>(manager_->GetOwner());
  if (character == nullptr)
    return;
  // Set the angle
  FVector2D input = character->GetMoveInputValue();
  if (input.Size() > 0.1f) {
    float angle = CalcuateMoveRadians(character, input);
    character->SetActorRotation(FRotator(0.0f, angle, 0.0f));
  }
  // DoAbility
  ability_->DoAbility();
}

void UInputRotateAbility::EndAbility() { ability_->EndAbility(); }

// 入力方向への回転をする
// この方が操作が直感的
float UInputRotateAbility::CalcuateMoveRadians(AMyCharacter *character, FVector2D input) {
  // Calculate the move direction
  input = {-input.X, input.Y};
  // Get the camera forward vector
  FVector2D cameraForward = character->GetCameraForwardVector();
  // calculate
  FVector2D moveDirection = input.GetRotated(
      -FMath::RadiansToDegrees(FMath::Atan2(cameraForward.X, cameraForward.Y)));
  // Check actor forward and move direction
  return FMath::RadiansToDegrees(FMath::Atan2(moveDirection.Y, moveDirection.X));
}
