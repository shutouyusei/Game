#include "InputComboAbility.h"
#include "../AbilityManager.h"
#include "Math/UnrealMathUtility.h"
#include "MyCharacter.h"

void UInputComboAbility::BeginPlay() {
  // Create the ability
  Ability_ = NewObject<UAbility>(this, InputAbility_);
  Ability_->SetManager(manager_);
  Ability_->BeginPlay();
}

void UInputComboAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Ability_->EndPlay(EndPlayReason);
  Ability_->ConditionalBeginDestroy();
}

void UInputComboAbility::DoAbility() {
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
  Ability_->DoAbility();
}

void UInputComboAbility::EndAbility() { Ability_->EndAbility(); }

// NOTE:より効率よいプログラムがあれば考える
float UInputComboAbility::CalcuateMoveRadians(AMyCharacter *character,
                                              FVector2D input) {
  // Calculate the move direction
  // Get the forward vector of the character
  FVector actorForward = character->GetActorForwardVector();
  input = {-input.X, input.Y};
  // Get the camera forward vector
  FVector2D cameraForward = character->GetCameraForwardVector();
  // calculate
  FVector2D moveDirection = input.GetRotated(
      -FMath::RadiansToDegrees(FMath::Atan2(cameraForward.X, cameraForward.Y)));
  // Check actor forward and move direction
  float AngleRadians = FMath::Atan2(
      actorForward.X * moveDirection.Y - actorForward.Y * moveDirection.X,
      actorForward.X * moveDirection.X + actorForward.Y * moveDirection.Y);

  if (AngleRadians > FMath::DegreesToRadians(15.0f) ||
      AngleRadians < FMath::DegreesToRadians(-180.0f)) {
    float actorAngle =
        FMath::RadiansToDegrees(FMath::Atan2(actorForward.Y, actorForward.X));
    return 15.0f + actorAngle;
  } else if (AngleRadians < FMath::DegreesToRadians(-15.0f) ||
             AngleRadians > FMath::DegreesToRadians(180.0f)) {
    float actorAngle =
        FMath::RadiansToDegrees(FMath::Atan2(actorForward.Y, actorForward.X));
    return -15.0f + actorAngle;
  } else {
    return FMath::RadiansToDegrees(
        FMath::Atan2(moveDirection.Y, moveDirection.X));
  }
}
